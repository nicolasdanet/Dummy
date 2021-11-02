
#pragma once

#include <JuceHeader.h>
#include "LookAndFeel.hpp"
#include "MenuModel.hpp"
#include "MainWindow.hpp"
#include "TestWindow.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class PopupApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    PopupApplication()
    {
    }

    ~PopupApplication() = default;
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        DBG ("Hello!");
        
        juce::LookAndFeel::setDefaultLookAndFeel (&lnf_);
        
        commandManager_ = std::make_unique<juce::ApplicationCommandManager>();
        menu_           = std::make_unique<MenuModel> (commandManager_.get());
        mainWindow_     = std::make_unique<MainWindow>();
        
        commandManager_->registerAllCommandsForTarget (this);
    }

    void shutdown() override
    {
        testWindow_     = nullptr;
        mainWindow_     = nullptr;
        menu_           = nullptr;
        commandManager_ = nullptr;
        
        juce::LookAndFeel::setDefaultLookAndFeel (nullptr);
        
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
    static PopupApplication& getApplication()
    {
        PopupApplication* app = dynamic_cast<PopupApplication*> (juce::JUCEApplication::getInstance());
        jassert (app);
        return *app;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    ApplicationLookAndFeel lnf_;
        
public:
    std::unique_ptr<juce::ApplicationCommandManager> commandManager_;
    std::unique_ptr<MenuModel> menu_;
    
private:
    std::unique_ptr<MainWindow> mainWindow_;
    std::unique_ptr<TestWindow> testWindow_;
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
