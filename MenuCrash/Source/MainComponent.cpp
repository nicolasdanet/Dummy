#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    menuBar_.reset (new juce::MenuBarComponent (this));
    addAndMakeVisible (menuBar_.get());
    setApplicationCommandManagerToWatch (&commandManager_);
    commandManager_.registerAllCommandsForTarget (this);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================

juce::StringArray MainComponent::getMenuBarNames()
{
    return juce::StringArray ("Foo");
}

juce::PopupMenu MainComponent::getMenuForIndex (int n, const juce::String&)
{
    juce::PopupMenu menu;
    
    if (n == 0) {
    //
    menu.addCommandItem (&commandManager_, CommandIDs::bar);
    menu.addSeparator();
    menu.addCommandItem (&commandManager_, juce::StandardApplicationCommandIDs::quit);
    //
    }
    
    return menu;
}

void MainComponent::menuItemSelected (int, int)
{
}

//==============================================================================

juce::ApplicationCommandTarget* MainComponent::getNextCommandTarget()
{
    return nullptr;
}

void MainComponent::getAllCommands (juce::Array<juce::CommandID>& c)
{
    c.add (CommandIDs::bar);
}

void MainComponent::getCommandInfo (juce::CommandID c, juce::ApplicationCommandInfo& r)
{
    if (c == static_cast<int> (CommandIDs::bar)) { r.setInfo ("Bar...", "Bar", "Foo", 0); }
}

bool MainComponent::perform (const InvocationInfo& info)
{
    if (info.commandID == static_cast<int> (CommandIDs::bar)) { DBG ("?"); return true; }

    return false;
}
    
//==============================================================================

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto b = getLocalBounds();
    auto h = juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight();
    
    menuBar_->setBounds (b.removeFromTop (h));
}
