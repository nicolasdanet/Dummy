
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
        g.fillAll (juce::Colours::black);
        g.setFont (juce::Font (24.0f));
        g.setColour (juce::Colours::orange);
        g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    }

    void resized() override
    {
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
