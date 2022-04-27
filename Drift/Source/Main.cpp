
#include "MainComponent.h"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class DriftApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    DriftApplication()  = default;
    ~DriftApplication() = default;

public:
    const juce::String getApplicationName() override    { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override          { return true; }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void initialise (const juce::String& commandLine) override
    {
        const juce::File t = juce::File::getSpecialLocation (juce::File::currentApplicationFile);
        const juce::File f = t.getSiblingFile ("preferences.xml");
        
        preferences_ = std::make_unique<juce::PropertiesFile> (f, juce::PropertiesFile::Options());
        
        mainWindow_.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow_ = nullptr;
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

public:
    static juce::PropertiesFile* getPreferences()
    {
        DriftApplication* app = dynamic_cast<DriftApplication*> (JUCEApplication::getInstance());
        jassert (app);
        return app->preferences_.get();
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainWindow : public juce::DocumentWindow {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    MainWindow (juce::String name)
        : DocumentWindow (name,
                          juce::Desktop::getInstance().getDefaultLookAndFeel()
                                                      .findColour (juce::ResizableWindow::backgroundColourId),
                          DocumentWindow::allButtons,
                          false)
    {
        setUsingNativeTitleBar (true);
        setResizable (true, true);
        setContentOwned (new MainComponent(), true);
        
        makeVisible();
    }

    ~MainWindow()
    {
        juce::PropertiesFile* preferences = DriftApplication::getPreferences();
        
        preferences->setValue ("Position", juce::var (getWindowStateAsString()));
        
        DBG (juce::String ("Save / ") + preferences->getValue ("Position"));
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    void closeButtonPressed() override
    {
        JUCEApplication::getInstance()->systemRequestedQuit();
    }

    void makeVisible()
    {
        juce::PropertiesFile* preferences = DriftApplication::getPreferences();
    
        const juce::String s = preferences->getValue ("Position");

        if (s.isNotEmpty()) { DBG (juce::String ("Load / ") + s); restoreWindowStateFromString (s); }
    
        setVisible (true); addToDesktop(); toFront (true);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

private:
    std::unique_ptr<juce::PropertiesFile> preferences_;
    std::unique_ptr<MainWindow> mainWindow_;
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

START_JUCE_APPLICATION (DriftApplication)
