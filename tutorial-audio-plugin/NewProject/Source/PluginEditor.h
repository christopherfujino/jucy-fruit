/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/**
 */
class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor,
                                       private juce::Slider::Listener {
  public:
    NewProjectAudioProcessorEditor(NewProjectAudioProcessor &);
    ~NewProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics &) override;
    void resized() override;

  private:
    void sliderValueChanged(juce::Slider* slider) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor &audioProcessor;

    juce::Slider midiVolume;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)
};
