
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "BaseComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Commands.hpp"
#include "Main.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

BaseComponent::BaseComponent()
{
    BaseComponent::getCommandManager()->registerAllCommandsForTarget (this);
    
    addKeyListener (BaseComponent::getCommandManager()->getKeyMappings());
    
    setWantsKeyboardFocus (true);
}

BaseComponent::~BaseComponent()
{
    removeKeyListener (BaseComponent::getCommandManager()->getKeyMappings());
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::ApplicationCommandManager* BaseComponent::getCommandManager()
{
    CallOutApplication* app = dynamic_cast<CallOutApplication*> (juce::JUCEApplication::getInstance());
    jassert (app);
    juce::ApplicationCommandManager* c = app->commandManager_.get();
    jassert (c);
    return c;
}

juce::MenuBarModel* BaseComponent::getMenuModel()
{
    CallOutApplication* app = dynamic_cast<CallOutApplication*> (juce::JUCEApplication::getInstance());
    jassert (app);
    juce::MenuBarModel* m = app->menu_.get();
    jassert (m);
    return m;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::ApplicationCommandTarget* BaseComponent::getNextCommandTarget()
{
    return findFirstTargetParentComponent();
}

void BaseComponent::getAllCommands (juce::Array<juce::CommandID>& c)
{
    Commands::getAllCommands (c);
}

void BaseComponent::getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r)
{
    Commands::getCommandInfo (c, r);
}

bool BaseComponent::perform (const juce::ApplicationCommandTarget::InvocationInfo& info)
{
    return Commands::perform (info);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------