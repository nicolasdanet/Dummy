
#include "MainComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

MainComponent::MainComponent()
{
    for (int i = 0; i < numberOfItems_; ++i) { items_.push_back (std::make_unique<ItemComponent> (i)); }
    
    for (const auto& p : items_) { addChildComponent (*p); }
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
}

void MainComponent::resized()
{
    arrange (getLocalBounds().reduced (10));
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

namespace {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

juce::Grid::TrackInfo getRowTrack()
{
    return juce::Grid::TrackInfo (juce::Grid::Px (MainComponent::size_));
}

juce::Grid::TrackInfo getColumnTrack()
{
    return juce::Grid::TrackInfo (juce::Grid::Px (MainComponent::size_));
}

juce::Array<juce::Grid::TrackInfo> getTracks (int n, const juce::Grid::TrackInfo& track)
{
    juce::Array<juce::Grid::TrackInfo> t;
    
    t.insertMultiple (-1, track, n);
    
    return t;
}

juce::Array<juce::Grid::TrackInfo> getRows (const juce::Rectangle<int>& bounds)
{
    const int n = bounds.getHeight() / (MainComponent::gap_ + MainComponent::size_);
    
    return getTracks (n, getRowTrack());
}

juce::Array<juce::Grid::TrackInfo> getColumns (const juce::Rectangle<int>& bounds)
{
    const int n = bounds.getWidth() / (MainComponent::gap_ + MainComponent::size_);
    
    return getTracks (n, getColumnTrack());
}

juce::Array<juce::GridItem> getGridItems (const std::vector<std::unique_ptr<ItemComponent>>& components)
{
    juce::Array<juce::GridItem> items;
    
    for (const auto& p : components) {
    //
    const int size = static_cast<int> (MainComponent::size_ * 1.5);
    
    const juce::GridItem::Span span (2);
    
    p->setVisible (true);
    
    items.add (juce::GridItem (*p).withArea (span, span).withSize (size, size));
    //
    }
    
    return items;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void MainComponent::arrange (const juce::Rectangle<int>& bounds)
{
    juce::Grid grid;
    
    grid.justifyItems       = juce::Grid::JustifyItems::center;
    grid.alignItems         = juce::Grid::AlignItems::center;
    grid.justifyContent     = juce::Grid::JustifyContent::start;
    grid.alignContent       = juce::Grid::AlignContent::start;
    grid.autoFlow           = juce::Grid::AutoFlow::column;
    grid.templateRows       = getRows (bounds);
    grid.templateColumns    = getColumns (bounds);
    grid.autoColumns        = getColumnTrack();
    grid.autoRows           = getRowTrack();
    grid.rowGap             = juce::Grid::Px (gap_);
    grid.columnGap          = juce::Grid::Px (gap_);
    grid.items              = getGridItems (items_);
    
    grid.performLayout (bounds);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
