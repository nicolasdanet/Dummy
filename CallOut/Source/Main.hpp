
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#pragma once

#include "Define.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Commands.hpp"
#include "MenuModel.hpp"
#include "CallWindow.hpp"
#include "MainWindow.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class CallOutApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

public:
    CallOutApplication()  = default;
    ~CallOutApplication() = default;
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    const juce::String getApplicationName() override
    {
        return ProjectInfo::projectName;
    }
    
    const juce::String getApplicationVersion() override
    {
        return ProjectInfo::versionString;
    }
    
    bool moreThanOneInstanceAllowed() override
    {
        return false;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void initialise (const juce::String&) override
    {
        DBG ("Hello!");
        
        commandManager_ = std::make_unique<juce::ApplicationCommandManager>();
        menu_           = std::make_unique<MenuModel> (commandManager_.get());
        mainWindow_     = std::make_unique<MainWindow> (getApplicationName());
        callWindow_     = std::make_unique<CallWindow> ("Foo");
        
        commandManager_->registerAllCommandsForTarget (this);

        #if MENUBAR_GLOBAL
        
        juce::MenuBarModel::setMacMainMenu (menu_.get());
        
        #endif
    }

    void shutdown() override
    {
        #if MENUBAR_GLOBAL
        
        juce::MenuBarModel::setMacMainMenu (nullptr);
        
        #endif
        
        callWindow_     = nullptr;
        mainWindow_     = nullptr;
        menu_           = nullptr;
        commandManager_ = nullptr;
        
        DBG ("Shutdown!");
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String&) override
    {
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void getAllCommands (juce::Array<juce::CommandID>& c) override
    {
        juce::JUCEApplication::getAllCommands (c); Commands::getAllCommands (c);
    }

    void getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r) override
    {
        juce::JUCEApplication::getCommandInfo (c, r); Commands::getCommandInfo (c, r);
    }

    bool perform (const juce::ApplicationCommandTarget::InvocationInfo& info) override
    {
        if (Commands::perform (info) == false) { return juce::JUCEApplication::perform (info); }
        else {
            return true;
        }
    }
    
public:
    std::unique_ptr<juce::ApplicationCommandManager> commandManager_;
    std::unique_ptr<MenuModel> menu_;
    
private:
    std::unique_ptr<MainWindow> mainWindow_;
    std::unique_ptr<CallWindow> callWindow_;
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
