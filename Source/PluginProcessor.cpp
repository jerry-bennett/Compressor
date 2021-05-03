/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
using namespace std;

//==============================================================================
CompressorAudioProcessor::CompressorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),state(*this,nullptr,Identifier("ChainParameters"),createParameterLayout())
#endif
{
    //variables for output meter
    outputAnalyser  = magicState.createAndAddObject<foleys::MagicAnalyser>("output");
    outputMeter = magicState.createAndAddObject<foleys::MagicLevelSource>("outputMeter");
    outputAnalysing.attachToValue (magicState.getPropertyAsValue ("analyser:output"));
    
}

CompressorAudioProcessor::~CompressorAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout CompressorAudioProcessor::createParameterLayout(){
    
    //foley stuff
    
    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    
    params.push_back(std::make_unique<AudioParameterFloat>("GAIN","Gain",0,10,0.5));
    params.push_back(std::make_unique<AudioParameterFloat>("THRESHOLD","Threshold",0, 100, 1));
    params.push_back(std::make_unique<AudioParameterInt>("RATIO","Ratio",1, 10, 1));
    params.push_back(std::make_unique<AudioParameterFloat>("ATTACK","Attack",0.01f,1.f,0.01));
    params.push_back(std::make_unique<AudioParameterFloat>("RELEASE","Release",0.01f,1.f,0.01f));
    
    
    return {params.begin() , params.end()};
}
//==============================================================================
const String CompressorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CompressorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CompressorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CompressorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CompressorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CompressorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CompressorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CompressorAudioProcessor::setCurrentProgram (int index)
{
}

const String CompressorAudioProcessor::getProgramName (int index)
{
    return {};
}

void CompressorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void CompressorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    outputMeter->setupSource (getTotalNumOutputChannels(), inputSample, 500, 200);
}

void CompressorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CompressorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CompressorAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    //value tree state initations
    float gainValue = *state.getRawParameterValue("GAIN");
    float threshValue = *state.getRawParameterValue("THRESHOLD");
    float ratioValue = *state.getRawParameterValue("RATIO");
    float attackValue = *state.getRawParameterValue("ATTACK");
    float releaseValue = *state.getRawParameterValue("RELEASE");

    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        //auto* channelData = buffer.getWritePointer (channel);
        
        for (int n = 0; n < buffer.getNumSamples(); n++){
            //read one sample at a time
            //inputSample = buffer.getReadPointer(channel)[n];
            float x = buffer.getWritePointer(channel)[n];
            
            //variables in header
            float alphaA = exp(-log(9)/(Fs*attackValue));
            
            float alphaR = exp(-log(9)/(Fs*releaseValue));
            
            //detection path
    
            //need to get envelope, but on the dB scale
            //convert signal to dB scale
            in_dB = 20*(log10(abs(x)));
            if(in_dB < -144){
                in_dB = -144;
            }
            
            //static characteristics
            if(in_dB < (threshValue)*-1){
                scGain = in_dB;
            }else{
                scGain = (threshValue * -1) + (in_dB - threshValue)/ratioValue;
            }
            
            gainChange_dB = scGain - in_dB;
            
            //smoothing filter
            if(gainChange_dB < gainSmoothPrev){ // attack
                gainSmooth = (1 - alphaA) * gainChange_dB + alphaA * gainSmoothPrev;
            }
            else{
                gainSmooth = (1-alphaR) * gainChange_dB + alphaR * gainSmoothPrev;
            }
            //convert back to linear scale
            gr = pow(10, (gainSmooth/20.f));// 10^(gainSmooth/20.f);
            
            gainSmoothPrev = gainSmooth;
            
            float in = x * gr;
            
            buffer.getWritePointer(channel)[n] = in * gainValue;
            

        }
        if (outputAnalysing.get())
            outputAnalyser->pushSamples (buffer);

        outputMeter->pushSamples (buffer);
    }
}

//==============================================================================
bool CompressorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* CompressorAudioProcessor::createEditor()
{
    return new foleys::MagicPluginEditor (magicState, BinaryData::compressor1_xml, BinaryData::compressor1_xmlSize);
}

//==============================================================================
void CompressorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    magicState.getStateInformation (destData);
}

void CompressorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    magicState.setStateInformation(data, sizeInBytes, getActiveEditor());
}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CompressorAudioProcessor();
}
