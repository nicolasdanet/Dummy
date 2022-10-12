
#include "MainComponent.h"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

namespace {
    juce::String debug (const juce::ValueTree& tree)
    {
        if (tree.getParent().isValid()) { return tree.getParent().getType().toString(); }
        else {
            return juce::String ("Invalid");
        }
    }
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

MainComponent::MainComponent()
{
    juce::ValueTree parent ("Parent");
    juce::ValueTree child ("Child");
    
    parent.appendChild (child, nullptr);
    
    tree_ = child;
    
    DBG (parent.getReferenceCount());       // 1
    DBG (tree_.getReferenceCount());        // 3
    DBG (debug (tree_));                    // "Parent"

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    DBG (tree_.getReferenceCount());        // 1
    DBG (debug (tree_));                    // "Invalid"
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
