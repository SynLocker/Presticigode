/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PanDelayGraph.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditorGUI  : public juce::AudioProcessorEditor,
                         public juce::Slider::Listener
{
public:
    //==============================================================================
    PluginEditorGUI (XDelayAudioProcessor& p);
    ~PluginEditorGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    XDelayAudioProcessor& audioProcessor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::Slider> juce__slider3;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<PanDelayGraph> juce__component;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Label> juce__label5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditorGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

