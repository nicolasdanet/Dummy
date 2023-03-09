
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "MainComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

MainComponent::MainComponent()
{
    #if !( MENUBAR_GLOBAL )

    menuBar_ = std::make_unique<juce::MenuBarComponent> (getMenuModel());

    addAndMakeVisible (menuBar_.get());

    #endif

    setOpaque (true); setSize (400, 300);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
    
}

void MainComponent::resized()
{
    #if !( MENUBAR_GLOBAL )
    
    const int h = juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight();
    
    menuBar_->setBounds (getLocalBounds().removeFromTop (h));
    
    #endif
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
