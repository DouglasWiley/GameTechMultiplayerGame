#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "BaseApplication.h"
#include "Game.h"
#include <sstream>
#include <string>
#include "SDL/SDL_mixer.h"

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

class GameManager : public BaseApplication
{
public:
  GameManager(void);
  virtual ~GameManager(void);
  void setUpLighting();

private:
  Game* game;
  CEGUI::OgreRenderer* mRenderer;
  CEGUI::Window *sheet;
  CEGUI::Window *gui;
  CEGUI::Window *scoreboard;
  CEGUI::Window *timer;

  int score;
  float time;
  bool soundOn;
  void placeIntInDisplay(CEGUI::Window* display, std::string title, const int num);
  void createMenu();
  void createScoreboard();

protected:
    virtual void createScene(void);
    virtual void createCamera();
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
    virtual void createFrameListener(void);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    bool renderGame(const CEGUI::EventArgs &e);
};

#endif