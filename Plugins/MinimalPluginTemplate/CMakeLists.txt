project(MinimalPluginTemplate VERSION 0.0.1)

set (BaseTargetName MinimalPluginTemplate)


function(createPluginVersion targetName version)
    juce_add_plugin(${targetName}
            COMPANY_NAME "TestJUCE"
            IS_SYNTH FALSE
            NEEDS_MIDI_INPUT TRUE
            NEEDS_MIDI_OUTPUT FALSE
            IS_MIDI_EFFECT FALSE
            EDITOR_WANTS_KEYBOARD_FOCUS FALSE
            COPY_PLUGIN_AFTER_BUILD TRUE
            PLUGIN_MANUFACTURER_CODE Tjuc
            PLUGIN_CODE MIpl
            FORMATS AU VST3
            PRODUCT_NAME "Parameter Test")

    target_sources(${targetName} PRIVATE
            Source/PluginProcessor.cpp)

    target_compile_definitions(${targetName}
            PUBLIC
            JUCE_WEB_BROWSER=0
            JUCE_USE_CURL=0
            JUCE_VST3_CAN_REPLACE_VST2=0
            PLUGIN_TEST_VERSION=${version})

    target_link_libraries(${targetName} PRIVATE
            shared_plugin_helpers
            juce_recommended_config_flags
            juce_recommended_lto_flags
            juce_recommended_warning_flags)

endfunction()

createPluginVersion(OriginalVersion 1)
createPluginVersion(NewParamsOutOfOrder 2)
createPluginVersion(NewParamsInOrder 3)