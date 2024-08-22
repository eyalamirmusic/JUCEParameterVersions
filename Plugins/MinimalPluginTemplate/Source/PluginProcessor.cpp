#include "PluginProcessor.h"

MinimalAudioPlugin::MinimalAudioPlugin()
{
#if PLUGIN_TEST_VERSION == 2
    addParameter(c);
#endif

    addParameter(a);
    addParameter(b);

#if PLUGIN_TEST_VERSION == 3
    addParameter(c);
#endif
}

void MinimalAudioPlugin::processBlock(juce::AudioBuffer<float>& buffer,
                                      juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    buffer.clear();
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MinimalAudioPlugin();
}
