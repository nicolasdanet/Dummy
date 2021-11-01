
#pragma once

#include <JuceHeader.h>
#include "Commands.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MenuModel : public juce::MenuBarModel {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit MenuModel (juce::ApplicationCommandManager* m)
    {
        jassert (m != nullptr);
        commandManager_ = m;
        setApplicationCommandManagerToWatch (commandManager_);
    }
    
    ~MenuModel() = default;

public:
    juce::StringArray getMenuBarNames() override
    {
        return { "Foo" };
    }

    juce::PopupMenu getMenuForIndex (int, const juce::String&) override;

    void menuItemSelected (int, int) override;

private:
    juce::ApplicationCommandManager* commandManager_;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MenuModel)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
