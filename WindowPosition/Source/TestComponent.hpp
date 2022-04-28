
#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class TestComponent : public juce::Component {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit TestComponent()
    {
        setOpaque (true);
        
        for (auto& button : buttons_) { button.setButtonText ("Foo"); addAndMakeVisible (button); }
        
        setSize (400, 300);
    }
    
    ~TestComponent() = default;

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
        juce::Rectangle<int> b (getLocalBounds());
        
        for (auto& button : buttons_) { button.setBounds (b.removeFromTop (24)); }
    }

private:
    std::array<juce::TextButton, 8> buttons_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

