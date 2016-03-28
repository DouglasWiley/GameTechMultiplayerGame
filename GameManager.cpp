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

    if(timer && scoreboard){
        if(time <= 0){
            CEGUI::WindowManager::getSingleton().destroyWindow(scoreboard);
            CEGUI::WindowManager::getSingleton().destroyWindow(timer);
            timer = NULL;
            scoreboard = NULL;
            CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
            CEGUI::Window *endDisplay = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
            placeIntInDisplay(endDisplay, "Game over! Final Score: ", score);
            endDisplay->setSize(CEGUI::USize(CEGUI::UDim(1, 0), CEGUI::UDim(1, 0)));
            gui->addChild(endDisplay);
        }
        else{
            placeIntInDisplay(scoreboard, "Score: ", score);
            time -= evt.timeSinceLastFrame;
            placeIntInDisplay(timer, "Time: ", int(time));
        }
    }

    if(game)
        game->frameRenderingQueued(evt, time);

    return true;
}
//---------------------------------------------------------------------------
void GameManager::createScene(void)
{
    game = NULL;
    score = 0;
    time = 60;
    soundOn = true;
    setUpLighting();
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    createMenu();
}

void GameManager::createMenu(){
    sheet = NULL;
    gui = NULL;
    timer = NULL;
    scoreboard = NULL;
    mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

    CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
    CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
    CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

    CEGUI::Window *startSinglePlayer = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
    startSinglePlayer->setText("Single Player Mode");
    startSinglePlayer->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    startSinglePlayer->setPosition(CEGUI::UVector2( CEGUI::UDim(0.425f, 0), CEGUI::UDim(0.375f, 0)));
    
    sheet->addChild(startSinglePlayer);
    startSinglePlayer->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameManager::renderGame, this));

    CEGUI::Window *startServer = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
    startServer->setText("Create Server");
    startServer->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    startServer->setPosition(CEGUI::UVector2( CEGUI::UDim(0.425f, 0), CEGUI::UDim(0.475f, 0)));
    
    sheet->addChild(startServer);
    startServer->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameManager::renderGame, this));

    CEGUI::Window *startClient = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
    startClient->setText("Join Server");
    startClient->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    startClient->setPosition(CEGUI::UVector2( CEGUI::UDim(0.425f, 0), CEGUI::UDim(0.575f, 0)));
    
    sheet->addChild(startClient);
    startClient->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameManager::renderGame, this));   
}

void GameManager::createScoreboard()
{
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    gui = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
    CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(gui);
    scoreboard = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
    placeIntInDisplay(scoreboard, "Score: ", score);
    scoreboard->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    gui->addChild(scoreboard);

    timer = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
    placeIntInDisplay(timer, "Time: ", time);
    timer->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    timer->setPosition(CEGUI::UVector2( CEGUI::UDim(0, 0), CEGUI::UDim(0.05f, 0)));

    gui->addChild(timer);
}

void GameManager::placeIntInDisplay(CEGUI::Window* display, std::string title, const int num){
    std::ostringstream convert;
    convert << title << num;
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

    if(arg.key == OIS::KC_M){
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
    
    if(game && time > 0)
        game->keyPressed(arg);
    return true;
}

bool GameManager::keyReleased( const OIS::KeyEvent &arg )
{   
    if(game && time > 0)
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

CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID)
{
    switch (buttonID)
    {
    case OIS::MB_Left:
        return CEGUI::LeftButton;
 
    case OIS::MB_Right:
        return CEGUI::RightButton;
 
    case OIS::MB_Middle:
        return CEGUI::MiddleButton;
 
    default:
        return CEGUI::LeftButton;
    }
}

bool GameManager::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    if(sheet)
        CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(convertButton(id));
    return true;
}

bool GameManager::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    if(sheet)
        CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(convertButton(id));
    return true;
}

bool GameManager::mouseMoved(const OIS::MouseEvent &arg)
{
    if(sheet){
        CEGUI::System &sys = CEGUI::System::getSingleton();
        sys.getDefaultGUIContext().injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
        // Scroll wheel.
        if (arg.state.Z.rel)
            sys.getDefaultGUIContext().injectMouseWheelChange(arg.state.Z.rel / 120.0f);
    }else{
        mCameraMan->injectMouseMove(arg);
    }
    return true;
}

bool GameManager::renderGame(const CEGUI::EventArgs &e)
{
    game = new DefaultGame();
    game->createScene(mSceneMgr, mCamera, time, score, soundOn);
    createScoreboard();
    if(sheet){
        CEGUI::WindowManager::getSingleton().destroyWindow(sheet);
        sheet = NULL;
        CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().hide();        
    }
    return true;
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
