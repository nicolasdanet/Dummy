
#pragma once

#include <JuceHeader.h>
#include "BipMenuModel.hpp"
#include "MainWindow.hpp"

class BipApplication : public juce::JUCEApplication
{
public:
    BipApplication() { }

    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        DBG ("Hello!");
        
        commandManager_ = std::make_unique<juce::ApplicationCommandManager>();
        menu_           = std::make_unique<MenuModel> (commandManager_.get());
        mainWindow_     = std::make_unique<MainWindow>();
        
        commandManager_->registerAllCommandsForTarget (this);
        juce::PopupMenu menu (MenuModel::createAppleMenu (commandManager_.get()));
        juce::MenuBarModel::setMacMainMenu (menu_.get(), &menu);
    }

    void shutdown() override
    {
        juce::MenuBarModel::setMacMainMenu (nullptr);
        
        mainWindow_     = nullptr;
        menu_           = nullptr;
        commandManager_ = nullptr;
        
        DBG ("Shutdown!");
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override
    {
    }

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

private:
    std::unique_ptr<MenuModel> menu_;
    std::unique_ptr<MainWindow> mainWindow_;
};
