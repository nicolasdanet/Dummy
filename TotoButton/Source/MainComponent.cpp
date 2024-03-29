
#include "MainComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void MainComponent::resized()
{
    juce::Rectangle<int> b (getLocalBounds().reduced (4));
        
    button_.setBounds (b.removeFromTop (24));
    b.removeFromTop (4);
    box_.setBounds (b.removeFromTop (24));
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

