
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#pragma once

#include "Define.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "BaseComponent.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class CallComponent : public BaseComponent {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit CallComponent();
    
    ~CallComponent() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<juce::MenuBarComponent> menuBar_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CallComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
