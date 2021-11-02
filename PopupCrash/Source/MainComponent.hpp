
#pragma once

#include <JuceHeader.h>
#include "BaseComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainComponent : public BaseComponent {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit MainComponent() : BaseComponent(), button_ ("Open the crash window")
    {
        initializeButton (button_); addAndMakeVisible (button_);
        
        setSize (300, 200);
    }
    
    ~MainComponent() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);
    }
    
    void resized() override
    {
        juce::Rectangle<int> b (setMenuBarBoundsAndGetRemaining().reduced (4));
        
        button_.setBounds (b.removeFromTop (24));
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    static void initializeButton (juce::TextButton& button);
    
private:
    juce::TextButton button_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

