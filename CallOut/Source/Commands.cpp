
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Commands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Commands::getAllCommands (juce::Array<juce::CommandID>& c)
{
    juce::Array<juce::CommandID> commands { Commands::bar };
        
    c.addArray (commands);
}

void Commands::getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r)
{
    switch (c) {
    //
    case Commands::bar :
        r.setInfo ("Bar", "Bar", "Foo", 0);
        r.addDefaultKeypress (juce::KeyPress::escapeKey, juce::ModifierKeys::noModifiers);
        break;
    default : break;
    //
    }
}

bool Commands::perform (const juce::ApplicationCommandTarget::InvocationInfo& info)
{
    return true;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
