/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SimpleMeter.h"

//==============================================================================
/**
*/
class OtherLookAndFeel : public LookAndFeel_V4{
public:
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override{
        
        float diameter = jmin(width, height);
        float diameter2 = jmin(width, height);
        float radius = diameter/2;
        float centerX = x + width/2;
        float centerY = y + height/2;
        float rx = centerX - (radius-1.5);
        float ry = centerY - (radius-1.5);
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        g.setColour(Colours::red);
        Rectangle<float> dialAreaOut(rx, ry, diameter2, diameter2);
        //test where bounds are
        //g.drawRect(dialAreaOut);
        g.setColour(Colours::antiquewhite);
        g.drawEllipse(dialAreaOut, 2.f);
        Rectangle<float> dialAreaIn(rx, ry, diameter, diameter);
        //g.drawRect(dialAreaIn);
        g.setColour(Colours::darkgrey);
        g.fillEllipse(dialAreaIn);
        
        g.setColour(Colours::antiquewhite);
        //g.fillEllipse(centerX, centerY, 10, 10);
        Path dialTick;
        dialTick.addRectangle(0, -(radius), 2.0f, (radius) * 0.33);//adjust numbers
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
        
        
        
    }
};
class CompressorAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener
{
public:
    CompressorAudioProcessorEditor (CompressorAudioProcessor&);
    ~CompressorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;
    

private:
    
    CompressorAudioProcessor& processor;
    
    //sliders
    Slider thresholdSlider;
    Slider gainSlider;
    Slider ratioSlider;
    Slider attackSlider;
    Slider releaseSlider;
    
    //variables for custom knob
    OtherLookAndFeel otherLookAndFeel;
    
    SimpleMeter meter;
    
    SimpleMeter meterIn;
    
    std::vector<std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressorAudioProcessorEditor)
};
