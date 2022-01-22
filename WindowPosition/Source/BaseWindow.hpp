
#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class BaseWindow : public juce::DocumentWindow {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit BaseWindow (const juce::String& name) :
        juce::DocumentWindow (name, juce::Colours::black, DocumentWindow::allButtons, false)
    {
        setUsingNativeTitleBar (true);
        setResizable (true, true);
    }
    
    ~BaseWindow() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void makeVisible (juce::Rectangle<int> window = juce::Rectangle<int>())
    {
        if (!window.isEmpty()) { setBounds (window); }
    
        setVisible (true); addToDesktop(); toFront (true);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseWindow)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
