
#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainComponent : public juce::Component {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit MainComponent() : buttonOpen_ ("Open the window"), buttonClose_ ("Close the window")
    {
        initializeButtons();
        
        addAndMakeVisible (buttonOpen_);
        addAndMakeVisible (buttonClose_);
        
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
        juce::Rectangle<int> b (getLocalBounds());
        
        buttonOpen_.setBounds (b.removeFromTop (24));
        buttonClose_.setBounds (b.removeFromTop (24));
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    void initializeButtons();
    
private:
    juce::TextButton buttonOpen_;
    juce::TextButton buttonClose_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

