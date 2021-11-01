
#include "MenuModel.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::PopupMenu MenuModel::getMenuForIndex (int n, const juce::String&)
{
    juce::PopupMenu menu;
    
    if (n == 0) {
        menu.addCommandItem (commandManager_, Commands::foo);
        menu.addCommandItem (commandManager_, Commands::bar);
    }
    
    return menu;
}

void MenuModel::menuItemSelected (int n, int index)
{
}
 
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
