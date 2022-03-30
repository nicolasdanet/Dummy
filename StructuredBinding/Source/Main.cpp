
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

#include <JuceHeader.h>

#include "MainComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

class StructuredBindingApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    StructuredBindingApplication() {}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void initialise (const juce::String& commandLine) override
    {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override
    {
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

    class MainWindow : public juce::DocumentWindow {
    
    public:
        MainWindow (juce::String name)
            : DocumentWindow (name,
                              juce::Desktop::getInstance().getDefaultLookAndFeel()
                                                          .findColour (juce::ResizableWindow::backgroundColourId),
                              DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

    public:
        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

START_JUCE_APPLICATION (StructuredBindingApplication)

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

