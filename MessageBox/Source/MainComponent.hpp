
#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainComponent : public juce::Component {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    static auto launchMessageBox (juce::Component* associatedComponent)
    {
        return [c = associatedComponent]()
        {
            auto f = [] (int result) { DBG (result); };
    
            juce::NativeMessageBox::showYesNoCancelBox (juce::MessageBoxIconType::QuestionIcon,
                "Foo",
                "Bar",
                c,
                juce::ModalCallbackFunction::create (f));
        };
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit MainComponent() : button_ ("Launch MessageBox")
    {
        button_.onClick = launchMessageBox (this);
        
        addAndMakeVisible (button_);
        
        setSize (600, 300);
    }
    
    ~MainComponent() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);
    }
    
    void resized() override
    {
        button_.setBounds (getLocalBounds().removeFromTop (24));
    }

private:
    juce::TextButton button_;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

