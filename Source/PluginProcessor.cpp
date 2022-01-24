/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditorGUI.h"

//==============================================================================
XDelayAudioProcessor::XDelayAudioProcessor() : 
    ppvts(*this, nullptr, Identifier("XDelayParams"), {
            std::make_unique<AudioParameterFloat>(NAME_PAN, "Pan", -1.0f, 1.0f, DEFAULT_PAN),
            std::make_unique<AudioParameterFloat>(NAME_DELAY, "Delay", 0.0f, MAX_DELAY_TIME, DEFAULT_DELAY),
            std::make_unique<AudioParameterFloat>(NAME_FEEDBACK, "Feedback", 0.0f, 1.0f, DEFAULT_FEEDBACK),
            std::make_unique<AudioParameterFloat>(NAME_TONE, "Tone", -1.0f, 1.0f, DEFAULT_TONE),
            std::make_unique<AudioParameterFloat>(NAME_MIX, "Mix", 0.0f, 1.0f, DEFAULT_MIX),
            std::make_unique<AudioParameterBool>(NAME_BYPASS, "Mute", DEFAULT_BYPASS)
    })

{
    /*parameters.addParameterListener(NAME_GAIN, &panner);
    parameters.addParameterListener(NAME_PAN, &panner);
    parameters.addParameterListener(NAME_MUTE, &panner);*/
    ppvts.addParameterListener(NAME_PAN, this);
    ppvts.addParameterListener(NAME_FEEDBACK, this);
    ppvts.addParameterListener(NAME_DELAY, this);
    ppvts.addParameterListener(NAME_TONE, this);
    ppvts.addParameterListener(NAME_MIX, this);
}

XDelayAudioProcessor::~XDelayAudioProcessor()
{
}

//==============================================================================
const juce::String XDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool XDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool XDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool XDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double XDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int XDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int XDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void XDelayAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String XDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void XDelayAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void XDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void XDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void XDelayAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    DBG(paramID + " :" + std::to_string(newValue));
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool XDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

void XDelayAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool XDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* XDelayAudioProcessor::createEditor()
{
    return new PluginEditorGUI(*this, ppvts);
}

//==============================================================================
void XDelayAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = ppvts.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void XDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(ppvts.state.getType()))
            ppvts.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new XDelayAudioProcessor();
}
