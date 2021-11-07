
#include "MenuModel.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

juce::PopupMenu MenuModel::getMenuForIndex (int n, const juce::String&)
{
    juce::PopupMenu menu;
    
    if (n == 0) {
        juce::PopupMenu t; t.addItem (1, "Salade");
        
        menu.addSubMenu ("Menu", t);
        menu.addSeparator();
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
