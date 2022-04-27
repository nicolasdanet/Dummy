
#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainComponent  : public juce::Component {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    MainComponent()
    {
        setSize (600, 400);
    }
    
    ~MainComponent() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void paint (juce::Graphics& g) override
    {
        const juce::Rectangle<int> r (300, 300);
        const juce::Rectangle<int> w = getPeer()->getBounds();
        const juce::String t = juce::String (w.getWidth()) + " x " + juce::String (w.getHeight());
        
        g.fillAll (juce::Colours::orange);
        g.setColour (juce::Colours::black);
        g.fillRect (r);
        g.setFont (juce::Font (24.0f));
        g.setColour (juce::Colours::white);
        g.drawText (t, r, juce::Justification::centred, true);
    }

    void resized() override
    {
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void mouseDoubleClick (const juce::MouseEvent &) override
    {
        setSize (300, 300);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
