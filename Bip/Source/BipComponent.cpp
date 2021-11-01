
#include "BipComponent.hpp"
#include "Main.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::ApplicationCommandManager& BipComponent::getCommandManager()
{
    BipApplication* app = dynamic_cast<BipApplication*> (juce::JUCEApplication::getInstance());
    jassert (app);
    juce::ApplicationCommandManager *c = app->commandManager_.get();
    jassert (c);
    return *c;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
