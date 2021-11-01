#pragma once

#include <JuceHeader.h>

//==============================================================================

class MyLookAndFeel : public juce::LookAndFeel_V4 {

public:
    MyLookAndFeel()
    {
        setColour (juce::PopupMenu::backgroundColourId,             juce::Colours::black);
        setColour (juce::PopupMenu::highlightedBackgroundColourId,  juce::Colours::red);
        setColour (juce::PopupMenu::textColourId,                   juce::Colours::white);
        setColour (juce::PopupMenu::highlightedTextColourId,        juce::Colours::white);
    }
    
    ~MyLookAndFeel() = default;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyLookAndFeel)
};

//==============================================================================

class MainComponent:    public juce::Component,
                        public juce::ApplicationCommandTarget,
                        public juce::MenuBarModel
{
public:
    enum CommandIDs { bar = 0xff000001 };
    
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    juce::StringArray getMenuBarNames() override;
    juce::PopupMenu getMenuForIndex (int, const juce::String&) override;
    void menuItemSelected (int, int) override;

    //==============================================================================
    juce::ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands (juce::Array<juce::CommandID>&) override;
    void getCommandInfo (juce::CommandID, juce::ApplicationCommandInfo&) override;
    bool perform (const InvocationInfo&) override;
    
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ApplicationCommandManager commandManager_;
    std::unique_ptr<juce::MenuBarComponent> menuBar_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
