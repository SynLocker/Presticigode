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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
#include <JuceHeader.h>
//[/Headers]

#include "PluginEditorGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditorGUI::PluginEditorGUI (XDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider.get());
    juce__slider->setRange (0, 10, 0);
    juce__slider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__slider->addListener (this);

    juce__slider->setBounds (32, 56, 150, 64);

    juce__slider2.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider2.get());
    juce__slider2->setRange (0, 10, 0);
    juce__slider2->setSliderStyle (juce::Slider::RotaryHorizontalDrag);
    juce__slider2->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__slider2->addListener (this);

    juce__slider2->setBounds (32, 168, 150, 64);

    juce__slider3.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider3.get());
    juce__slider3->setRange (0, 10, 0);
    juce__slider3->setSliderStyle (juce::Slider::RotaryHorizontalDrag);
    juce__slider3->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__slider3->addListener (this);

    juce__slider3->setBounds (32, 280, 150, 64);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Feedback")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (64, 32, 72, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Mix(Dry/Wet)")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (56, 144, 104, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Tone")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (72, 256, 56, 24);

    juce__component.reset (new PanDelayGraph());
    addAndMakeVisible (juce__component.get());
    juce__component->setName ("new component");

    juce__component->setBounds (264, 64, 272, 272);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Echo Pan")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (14.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (368, 40, 72, 24);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("D\n"
                                         "e\n"
                                         "l\n"
                                         "a\n"
                                         "y")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (14.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centred);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (232, 96, 32, 208);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditorGUI::~PluginEditorGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__slider = nullptr;
    juce__slider2 = nullptr;
    juce__slider3 = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    juce__component = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditorGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditorGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditorGUI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider.get())
    {
        //[UserSliderCode_juce__slider] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider]
    }
    else if (sliderThatWasMoved == juce__slider2.get())
    {
        //[UserSliderCode_juce__slider2] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider2]
    }
    else if (sliderThatWasMoved == juce__slider3.get())
    {
        //[UserSliderCode_juce__slider3] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider3]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditorGUI" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="XDelayAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), audioProcessor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="f67974cc68240d99" memberName="juce__slider"
          virtualName="" explicitFocusOrder="0" pos="32 56 150 64" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="dd96fd0327d144bd" memberName="juce__slider2"
          virtualName="" explicitFocusOrder="0" pos="32 168 150 64" min="0.0"
          max="10.0" int="0.0" style="RotaryHorizontalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="641a8daa1a6ab101" memberName="juce__slider3"
          virtualName="" explicitFocusOrder="0" pos="32 280 150 64" min="0.0"
          max="10.0" int="0.0" style="RotaryHorizontalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="e7db6f463f9625bd" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="64 32 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="71906239077d1f59" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="56 144 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mix(Dry/Wet)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1d7a6ef62a273b24" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="72 256 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="new component" id="1e00799b4f26f6a5" memberName="juce__component"
                    virtualName="" explicitFocusOrder="0" pos="264 64 272 272" class="PanDelayGraph"
                    params=""/>
  <LABEL name="new label" id="76eabbd45fa5d54c" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="368 40 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Echo Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d2901eae0c75a9ec" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="232 96 32 208" edTextCol="ff000000"
         edBkgCol="0" labelText="D&#10;e&#10;l&#10;a&#10;y" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

