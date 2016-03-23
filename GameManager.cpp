#include "GameManager.h"
//---------------------------------------------------------------------------
GameManager::GameManager(void)
{

}
//---------------------------------------------------------------------------
GameManager::~GameManager(void)
{
}

bool GameManager::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    // Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();
    CEGUI::System::getSingleton().injectTimePulse(evt.timeSinceLastFrame);


    //mTrayMgr->frameRenderingQueued(evt);


    /*if (!mTrayMgr->isDialogVisible())
    {
        mCameraMan->frameRenderingQueued(evt);   // If dialog isn't up, then update the camera
        if (mDetailsPanel->isVisible())          // If details panel is visible, then update its contents
        {
            mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
            mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
            mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
            mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
            mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
            mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
            mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
        }
    }

    if(time <= 0){
        if(!endDisplay){
            endDisplay = mTrayMgr->createTextBox(OgreBites::TL_CENTER, "End Display", ("GAME OVER"), 1700, 900);
            std::ostringstream convert;
            convert << "YOUR FINAL SCORE WAS: \n" << score;
            endDisplay->setText(convert.str());
        }
        scoreDisplay->hide();
        timerDisplay->hide();
    }
    else{
        placeIntInDisplay(scoreDisplay, score);

        time -= evt.timeSinceLastFrame;
        placeIntInDisplay(timerDisplay, time);
    } */

    game->frameRenderingQueued(evt, time);

    return true;
}
//---------------------------------------------------------------------------
void GameManager::createScene(void)
{
    mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

    CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
    CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

    score = 0;
    time = 60;
    endDisplay = 0;
    soundOn = true;
    setUpLighting();
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

    //Setup Score
    /*scoreDisplay = mTrayMgr->createTextBox(OgreBites::TL_TOPLEFT, "Score", ("Score"), 100, 100);
    placeIntInDisplay(scoreDisplay, score);

    timerDisplay = mTrayMgr->createTextBox(OgreBites::TL_TOPLEFT, "Timer", ("Time Left:"), 100, 100);
    placeIntInDisplay(timerDisplay, time);*/

    game = new DefaultGame();
    game->createScene(mSceneMgr, mCamera, time, score, soundOn);
}

void GameManager::placeIntInDisplay(OgreBites::TextBox* display, const int num){
    std::ostringstream convert;
    convert << num;
    display->setText(convert.str());
}

void GameManager::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(-750, 750, -750));
    mCamera->lookAt(Ogre::Vector3(750, -750, 750));
    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(4000);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void GameManager::setUpLighting()
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    Ogre::Light* rLight = mSceneMgr->createLight( "rLight" );
    Ogre::Light* gLight = mSceneMgr->createLight( "gLight" );
    Ogre::Light* bLight = mSceneMgr->createLight( "bLight" );
    rLight->setType(Ogre::Light::LT_POINT);
    rLight->setPosition(0,400,0);
    rLight->setDiffuseColour(1,0,0);
    rLight->setSpecularColour(1,0,0);
    gLight->setType(Ogre::Light::LT_POINT);
    gLight->setPosition(-350,-250,0);
    gLight->setDiffuseColour(0,1,0);
    gLight->setSpecularColour(0,1,0);
    bLight->setType(Ogre::Light::LT_POINT);
    bLight->setPosition(350,-250,0);
    bLight->setDiffuseColour(0,0,1);
    bLight->setSpecularColour(0,0,1);
}

bool GameManager::keyPressed( const OIS::KeyEvent &arg )
{

    /*if (mTrayMgr->isDialogVisible()) 
        return true;   // don't process any more keys if dialog is up
    else if (arg.key == OIS::KC_G)   // toggle visibility of even rarer debugging details
    {
        if (mDetailsPanel->getTrayLocation() == OgreBites::TL_NONE)
        {
            mTrayMgr->moveWidgetToTray(mDetailsPanel, OgreBites::TL_TOPRIGHT, 0);
            mDetailsPanel->show();
        }
        else
        {
            mTrayMgr->removeWidgetFromTray(mDetailsPanel);
            mDetailsPanel->hide();
        }
    }
    else */if(arg.key == OIS::KC_M){
        soundOn = !soundOn;
    }
    else if(arg.key == OIS::KC_F5)   // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
    else if (arg.key == OIS::KC_ESCAPE)
    {
        mShutDown = true;
    }
    
    game->keyPressed(arg);
    return true;
}

bool GameManager::keyReleased( const OIS::KeyEvent &arg )
{   
    game->keyReleased(arg);
    return true;
}

void GameManager::createFrameListener(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
 
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
 
    mInputManager = OIS::InputManager::createInputSystem( pl );
 
    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
 
    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
 
    //Set initial mouse clipping size
    windowResized(mWindow);
 
    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
 
    mRoot->addFrameListener(this);
}
//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        GameManager app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
