
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
        juce::Component *c = options.getTargetComponent();
        const bool isBox = (dynamic_cast<juce::ComboBox*> (c) != nullptr);
        const bool isBar = (dynamic_cast<juce::MenuBarComponent*> (c) != nullptr);
        
        if (isBox) {
            g.fillAll (juce::Colours::green);
        } else if (isBar) {
            g.fillAll (juce::Colours::blue);
        } else {
            g.fillAll (juce::Colours::red);     DBG ("Called with already deleted component!");
        }
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ApplicationLookAndFeel)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
