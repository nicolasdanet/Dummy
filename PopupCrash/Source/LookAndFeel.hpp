
#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class ApplicationLookAndFeel : public juce::LookAndFeel_V4 {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

public:
    ApplicationLookAndFeel() = default;
    ~ApplicationLookAndFeel() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void drawPopupMenuBackgroundWithOptions (juce::Graphics& g,
        int width,
        int height,
        const juce::PopupMenu::Options& options) override
    {
        const bool isComboBox = (dynamic_cast<juce::ComboBox*> (options.getTargetComponent()) != nullptr);
        
        if (isComboBox) {
            g.fillAll (juce::Colours::green);
        } else {
            g.fillAll (juce::Colours::blue);
        }
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ApplicationLookAndFeel)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
