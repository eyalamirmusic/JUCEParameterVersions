#include "PluginProcessor.h"

enum class Versions
{
    Original,
    OutOfOrder,
    InOrder
};

static Versions getVersion()
{
    return Versions::PLUGIN_TEST_VERSION;
}

inline Param* createParam(const juce::String& name, int version)
{
    return new Param({name, version}, name, 0.f, 5.f, 3.f);
}

MinimalAudioPlugin::MinimalAudioPlugin()
{
    auto version = getVersion();

    if (version == Versions::OutOfOrder)
        addParameter(createParam("c", 2));

    if (version == Versions::Original || version == Versions::InOrder)
        addParameter(createParam("a", 1));

    addParameter(createParam("b", 1));

    if (version == Versions::InOrder)
        addParameter(createParam("c", 2));
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
