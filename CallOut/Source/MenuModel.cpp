
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "MenuModel.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Commands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

MenuModel::MenuModel (juce::ApplicationCommandManager* m)
{
    jassert (m != nullptr);
    commandManager_ = m;
    setApplicationCommandManagerToWatch (commandManager_);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::StringArray MenuModel::getMenuBarNames()
{
    return { "Foo" };
}
    
juce::PopupMenu MenuModel::getMenuForIndex (int n, const juce::String&)
{
    juce::PopupMenu menu;
    
    if (n == 0) { menu.addCommandItem (commandManager_, Commands::bar); }
    
    return menu;
}

void MenuModel::menuItemSelected (int n, int index)
{
}
 
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
