#pragma once

#include <JuceHeader.h>
#include "TotoButton.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainComponent : public juce::Component {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    MainComponent()
    {
        initializeBox (box_);
        
        addAndMakeVisible (button_);
        addAndMakeVisible (box_);
        
        setSize (300, 200);
    }
    
    ~MainComponent() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    static void addItemList (juce::PopupMenu& popup, const juce::StringArray& a, int firstItemID)
    {
        for (const auto& item : a) { popup.addItem (firstItemID++, item); }
    }
    
    static void initializeBox (juce::ComboBox& box)
    {
        const int n = 1234;
        const juce::StringArray a = { "Bijou", "Caillou", "Chou", "Genou", "Hibou", "Joujou", "Pou" };
        juce::PopupMenu t; addItemList (t, a, n);

        box.addItem ("Foo", 1);
        box.getRootMenu()->addSubMenu ("Bar", t);
        box.setSelectedId (n + 1);
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    TotoButton button_;
    juce::ComboBox box_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

