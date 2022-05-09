
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "MainComponent.h"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class XMLApplication : public juce::JUCEApplication {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    XMLApplication()  = default;
    ~XMLApplication() = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    const juce::String getApplicationName() override
    {
        return ProjectInfo::projectName;
    }
    const juce::String getApplicationVersion() override
    {
        return ProjectInfo::versionString;
    }
    
    bool moreThanOneInstanceAllowed() override
    {
        return true;
    }

    /*
    <?xml version="1.0" encoding="UTF-8"?>

    <PROPERTIES>
      <VALUE name="foo">
        <TrackInfo Name="Frucht_on_Ullman_Clean"
                   URL="C:\Users\HAL 9000\Downloads\Frucht_on_Ullman_Clean.wav"
                   Length="42.59999847412109"
                   BPM="112.3600006103516"
                   FirstBeatTime="0.064"
                   CuePoint1="-1.0"
                   CuePoint2="-1.0"
                   CuePoint3="-1.0"
                   CuePoint4="-1.0"/>
      </VALUE>
    </PROPERTIES>
    */
    
    float getTrackBpm (const juce::String& hash) const
    {
        const std::unique_ptr<juce::XmlElement> e (properties_->getXmlValue (hash));
        
        if (e && e->hasTagName ("TrackInfo")) {
        //
        jassert (e->hasAttribute ("BPM")); return e->getDoubleAttribute ("BPM", 0.0);
        //
        }
        
        return 0.0f;
    }
    
    void initialise (const juce::String& commandLine) override
    {
        DBG ("Hello!");

        const juce::File t = juce::File::getSpecialLocation (juce::File::currentApplicationFile);
        const juce::File f = t.getSiblingFile ("properties.xml");
        
        properties_ = std::make_unique<juce::PropertiesFile> (f, juce::PropertiesFile::Options());
        
        if (properties_->isValidFile()) { DBG (getTrackBpm ("foo")); }
        else {
            DBG ("?");
        }
        
        mainWindow_.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow_ = nullptr;
        
        DBG ("Shutdown!");
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override
    {
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class MainWindow : public juce::DocumentWindow {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    MainWindow (juce::String name) : DocumentWindow (name, juce::Colours::black, DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new MainComponent(), true);
        setResizable (true, true);
        centreWithSize (getWidth(), getHeight());
        setVisible (true);
    }

    void closeButtonPressed() override
    {
        JUCEApplication::getInstance()->systemRequestedQuit();
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    std::unique_ptr<juce::PropertiesFile> properties_;
    std::unique_ptr<MainWindow> mainWindow_;
};


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

START_JUCE_APPLICATION (XMLApplication)
