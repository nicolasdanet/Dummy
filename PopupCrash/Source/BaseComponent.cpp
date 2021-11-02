
#include "BaseComponent.hpp"
#include "Main.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::ApplicationCommandManager& BaseComponent::getCommandManager()
{
    PopupApplication* app = dynamic_cast<PopupApplication*> (juce::JUCEApplication::getInstance());
    jassert (app);
    juce::ApplicationCommandManager *c = app->commandManager_.get();
    jassert (c);
    return *c;
}

juce::MenuBarModel& BaseComponent::getMenuBarModel()
{
    PopupApplication* app = dynamic_cast<PopupApplication*> (juce::JUCEApplication::getInstance());
    jassert (app);
    juce::MenuBarModel *m = app->menu_.get();
    jassert (m);
    return *m;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
