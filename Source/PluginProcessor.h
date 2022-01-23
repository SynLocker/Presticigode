/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//PARAMETRI
#define NAME_PAN "Pan"
#define NAME_DELAY "Delay"
#define NAME_FEEDBACK "Feedback"
#define NAME_TONE "Tone"
#define NAME_MIX "Mix"
#define NAME_BYPASS "Bypass"

#define DEFAULT_PAN 0.0f
#define DEFAULT_DELAY  0.0f
#define DEFAULT_FEEDBACK  0.0f
#define DEFAULT_TONE  0.5f
#define DEFAULT_MIX  0.5f
#define DEFAULT_BYPASS false

#define MAX_DELAY_TIME   5.0f

using namespace juce;
//==============================================================================
/**
*/
class XDelayAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    XDelayAudioProcessor();
    ~XDelayAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    AudioProcessorValueTreeState ppvts;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XDelayAudioProcessor)
};
