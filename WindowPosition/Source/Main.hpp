
#pragma once

#include <JuceHeader.h>
#include "MainWindow.hpp"
#include "TestWindow.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class PositionApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    PositionApplication()
    {
    }

    ~PositionApplication() = default;
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        DBG ("Hello!");

        mainWindow_ = std::make_unique<MainWindow>();
    }

    void shutdown() override
    {
        mainWindow_ = nullptr;
        
        DBG ("Shutdown!");
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
    template <class T> static void createOrOpenWindow (std::unique_ptr<T>& p)
    {
        if (p == nullptr) { p = std::make_unique<T>(); } else { p.get()->toFront (true); }
    }
    
    void openTestWindow()
    {
        createOrOpenWindow (testWindow_);
    }

    void closeTestWindow()
    {
        testWindow_ = nullptr;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    static PositionApplication& getApplication()
    {
        PositionApplication* app = dynamic_cast<PositionApplication*> (juce::JUCEApplication::getInstance());
        jassert (app);
        return *app;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    std::unique_ptr<MainWindow> mainWindow_;
    std::unique_ptr<TestWindow> testWindow_;
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
