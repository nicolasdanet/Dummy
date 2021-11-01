
#include "Commands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Commands::getAllCommands (juce::Array<juce::CommandID>& c)
{
    juce::Array<juce::CommandID> commands
        {
            Commands::foo,
            Commands::bar,
        };
        
    c.addArray (commands);
}

void Commands::getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r)
{
    switch (c) {
    //
    case Commands::foo :
        r.setInfo ("Foo", "Go Foo", "General", 0);
        r.addDefaultKeypress ('f', juce::ModifierKeys::commandModifier);
        break;
    case Commands::bar :
        r.setInfo ("Bar", "Go Bar", "General", 0);
        r.addDefaultKeypress ('b', juce::ModifierKeys::commandModifier);
        break;
    default : break;
    //
    }
}

bool Commands::perform (const juce::ApplicationCommandTarget::InvocationInfo& info)
{
    switch (info.commandID) {
    //
    case Commands::foo : DBG ("Foo!"); return true;
    case Commands::bar : DBG ("Bar!"); return true;
    default : break;
    //
    }

    return false;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
