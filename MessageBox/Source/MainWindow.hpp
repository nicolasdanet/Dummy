
#pragma once

#include <JuceHeader.h>
#include "MainComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainWindow : public juce::DocumentWindow {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit MainWindow () :
        juce::DocumentWindow ("Main", juce::Colours::black, DocumentWindow::allButtons, false)
    {
        setContentOwned (new MainComponent(), true);
        
        setUsingNativeTitleBar (true);
        setResizable (true, true);
        setVisible (true);
        addToDesktop();
        toFront (true);
    }

    ~MainWindow() = default;
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void closeButtonPressed() override
    {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
