
#include "BaseWindow.hpp"
#include "Main.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void BaseWindow::makeVisible (juce::Rectangle<int> bounds)
{
    if (!bounds.isEmpty()) { setBounds (bounds); }
    else {
        const juce::String s (PositionApplication::getPreferences()->getValue ("Position"));

        if (s.isNotEmpty()) {
            DBG (s); restoreWindowStateFromString (s);
        }
    }
    
    setVisible (true); addToDesktop(); toFront (true);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
