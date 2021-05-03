/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor (CompressorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //fixed ratio
    double ratio = 4.0/3.0;
    setResizeLimits(400, 400/ratio, 1200, 1200/ratio);
    getConstrainer()->setFixedAspectRatio(ratio);
    setSize(800.0,800.0/ratio);
    
}


//==============================================================================
void CompressorAudioProcessorEditor::paint (Graphics& g)
{
    //threhsold slider
    thresholdSlider.setSliderStyle(Slider::LinearBarVertical);
    thresholdSlider.setBounds(400, 150, 150, 150);
    thresholdSlider.setRange(0, 200, 1);
    thresholdSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(thresholdSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state,"THRESHOLD",thresholdSlider));
    
    
    //ratio slider
    ratioSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    ratioSlider.setBounds(100, 250, 150, 150);
    ratioSlider.setRange(1, 10, 1);
    ratioSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(ratioSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state,"RATIO",ratioSlider));
    
    //attack slider
    
    //release slider
    
    //gain slider
    gainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setBounds(200, 200, 150, 150);
    gainSlider.setRange(0, 10, 1);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    gainSlider.setLookAndFeel(&otherLookAndFeel);
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state,"GAIN",gainSlider));
    addAndMakeVisible(gainSlider);
    
    //attack slider
    attackSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider.setBounds(100, 50, 150, 150);
    attackSlider.setRange(0.01, 1, 0.01);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state,"ATTACK",attackSlider));
    addAndMakeVisible(attackSlider);
    
    //release slider
    releaseSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider.setBounds(200, 50, 150, 150);
    releaseSlider.setRange(0.01, 1, 0.01);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state,"RELEASE",releaseSlider));
    addAndMakeVisible(releaseSlider);
}

CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor(){
}

void CompressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void CompressorAudioProcessorEditor::sliderValueChanged(Slider *slider) {
    
}
