
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "CallComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

CallComponent::CallComponent() : BaseComponent()
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

void CallComponent::paint (juce::Graphics& g)
{
    const juce::Rectangle<int> r (getLocalBounds());
    const juce::String text ("Press Escape Key");
    
    g.setColour (juce::Colours::darkgrey);
    g.fillRect (r);
    g.setColour (juce::Colours::white);
    g.setFont (juce::Font (18.0f));
    g.drawText (text, r, juce::Justification::centred, true);
}

void CallComponent::resized()
{
    #if !( MENUBAR_GLOBAL )
    
    const int h = juce::LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight();
    
    menuBar_->setBounds (getLocalBounds().removeFromTop (h));
    
    #endif
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
