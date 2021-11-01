
#pragma once

#include <JuceHeader.h>
#include "Commands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class BaseComponent :   public juce::Component,
                        public juce::ApplicationCommandTarget {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit BaseComponent()
    {
        BaseComponent::getCommandManager().registerAllCommandsForTarget (this);
        
        addKeyListener (BaseComponent::getCommandManager().getKeyMappings());
        
        menubar_ = std::make_unique<juce::MenuBarComponent> (&BaseComponent::getMenuBarModel());
        addAndMakeVisible (menubar_.get());
        
        setWantsKeyboardFocus (true);
        setOpaque (true);
    }
    
    ~BaseComponent() override
    {
        juce::PopupMenu::dismissAllActiveMenus();
        
        removeKeyListener (BaseComponent::getCommandManager().getKeyMappings());
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

protected:
    juce::Rectangle<int> setMenuBarBoundsAndGetRemaining()
    {
        juce::Rectangle<int> b = getLocalBounds();

        menubar_->setBounds (b.removeFromTop (24));
        
        return b;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    static juce::ApplicationCommandManager& getCommandManager();
    static juce::MenuBarModel& getMenuBarModel();
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    juce::ApplicationCommandTarget* getNextCommandTarget() override
    {
        return findFirstTargetParentComponent();
    }

    void getAllCommands (juce::Array<juce::CommandID>& c) override
    {
        Commands::getAllCommands (c);
    }

    void getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r) override
    {
        Commands::getCommandInfo (c, r);
    }

    bool perform (const juce::ApplicationCommandTarget::InvocationInfo& info) override
    {
        return Commands::perform (info);
    }

private:
    std::unique_ptr<juce::MenuBarComponent> menubar_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

