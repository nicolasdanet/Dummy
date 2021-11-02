
#pragma once

#include <JuceHeader.h>
#include "Component.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class TestComponent : public BaseComponent {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit TestComponent() : BaseComponent()
    {
        initializeComboBox (box_); addAndMakeVisible (box_);
        
        setSize (300, 200);
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
        juce::Rectangle<int> b (setMenuBarBoundsAndGetRemaining().reduced (4));
        
        box_.setBounds (b.removeFromTop (24));
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    static void initializeComboBox (juce::ComboBox& box)
    {
        box.addItemList ( { "Bijou", "Caillou", "Chou", "Genou", "Hibou", "Joujou", "Pou" } , 1);
    }
    
private:
    juce::ComboBox box_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

