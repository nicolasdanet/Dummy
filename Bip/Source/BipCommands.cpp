
#include "BipCommands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Commands::getAllCommands (juce::Array<juce::CommandID>& c)
{
    juce::Array<juce::CommandID> commands
        {
            Commands::preferences,
            Commands::bar,
        };
        
    c.addArray (commands);
}

void Commands::getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r)
{
    switch (c) {
    //
    case Commands::preferences :
        r.setInfo ("Preferences...", "Set preferences", "General", 0);
        r.addDefaultKeypress (',', juce::ModifierKeys::commandModifier);
        break;
    case Commands::bar :
        r.setInfo ("Bar", "Bar", "Foo", 0);
        r.addDefaultKeypress ('n', juce::ModifierKeys::commandModifier);
        break;
    default : break;
    //
    }
}

bool Commands::perform (const juce::ApplicationCommandTarget::InvocationInfo& info)
{
    switch (info.commandID) {
    //
    case Commands::preferences  : DBG ("Preferences!"); return true;
    case Commands::bar          : DBG ("Bar!");         return true;
    default : break;
    //
    }

    return false;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
