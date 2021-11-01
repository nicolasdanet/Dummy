
#include <JuceHeader.h>

//==============================================================================
class FooApplication :  public juce::JUCEApplication,
                        public juce::MenuBarModel
{
public:
    //==============================================================================
    FooApplication() {}

    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    //==============================================================================
    void initialise (const juce::String&) override
    {
        DBG ("Hello!");
        
        setApplicationCommandManagerToWatch (&commandManager_);
        
        commandManager_.registerAllCommandsForTarget (this);
        
        #if ( JUCE_MAC )
        
        juce::MenuBarModel::setMacMainMenu (this);
        
        #endif
    }

    void shutdown() override
    {
        #if ( JUCE_MAC )
        
        juce::MenuBarModel::setMacMainMenu (nullptr);
        
        #endif
        
        DBG ("Goodbye!");
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String&) override
    {
    }
    
    //==============================================================================
    enum CommandIDs : juce::CommandID { newWindow = 0x7f00fada };

    void getAllCommands (juce::Array<juce::CommandID>& c) override
    {
        JUCEApplication::getAllCommands (c);
        
        juce::Array<juce::CommandID> commands { CommandIDs::newWindow };
        
        c.addArray (commands);
    }

    void getCommandInfo (const juce::CommandID c, juce::ApplicationCommandInfo& r) override
    {
        switch (c) {
        //
        case CommandIDs::newWindow :
            r.setInfo ("New Window", "Opens another window", "Application", 0);
            r.addDefaultKeypress ('n', juce::ModifierKeys::commandModifier);
            break;
        default : break;
        //
        }
    
        JUCEApplication::getCommandInfo (c, r);
    }

    bool perform (const InvocationInfo& info) override
    {
        if (JUCEApplication::perform (info)) { return true; }
        else {
            switch (info.commandID) {
            //
            case CommandIDs::newWindow : DBG ("?"); return true;
            default : break;
            //
            }
        }
        
        return false;
    }

//==============================================================================
    juce::StringArray getMenuBarNames() override
    {
        return { "Application" };
    }

    juce::PopupMenu getMenuForIndex (int n, const juce::String&) override
    {
        juce::PopupMenu menu;
        
        if (n == 0) { menu.addCommandItem (&commandManager_, CommandIDs::newWindow); }
        
        return menu;
    }

    void menuItemSelected (int, int) override
    {
    }
    
private:
    juce::ApplicationCommandManager commandManager_;
};

//==============================================================================

START_JUCE_APPLICATION (FooApplication)
