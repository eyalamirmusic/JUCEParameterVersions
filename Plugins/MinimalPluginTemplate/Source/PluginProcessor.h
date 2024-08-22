#pragma once

#include <shared_plugin_helpers/shared_plugin_helpers.h>

using Param = juce::AudioParameterFloat;

inline Param* createParam(const juce::String& name, int version)
{
    return new Param({name, version}, name, 0.f, 5.f, 3.f);
}

class MinimalAudioPlugin : public PluginHelpers::ProcessorBase
{
public:
    MinimalAudioPlugin();
    void processBlock(juce::AudioBuffer<float>& buffer,
                      juce::MidiBuffer& midiMessages) override;

    //V1:
    Param* a = createParam("a", 1);
    Param* b = createParam("b", 1);

    //V2 or V3:
    Param* c = createParam("c", 2);
};
