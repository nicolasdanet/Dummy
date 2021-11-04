
#include <JuceHeader.h>

//==============================================================================

class MainComponent  : public juce::Component {

public:
    MainComponent()
    {
        setSize (600, 400);
    }
    
    ~MainComponent() = default;

public:
    void paint (juce::Graphics& g) override
    {
        const juce::Rectangle<int> r (300, 300);
        
        g.fillAll (juce::Colours::orange);
        g.setColour (juce::Colours::black);
        g.fillRect (r);
        g.setFont (juce::Font (24.0f));
        g.setColour (juce::Colours::white);
        g.drawText ("300 x 300", r, juce::Justification::centred, true);
    }

    void resized() override
    {
    }
    
    void mouseDoubleClick (const juce::MouseEvent &) override
    {
        setSize (300, 300);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
