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
  CEGUI::Window *menu;
  CEGUI::Window *editboxDialogue;
  CEGUI::Window *editbox;
  CEGUI::Window *gui;
  CEGUI::Window *scoreboard;
  CEGUI::Window *scoreboard2;
  CEGUI::Window *timer;

  int score;
  int score1;
  int score2;
  float time;
  bool soundOn;
  bool multiplayer;

  void placeIntInDisplay(CEGUI::Window* display, std::string title, const int num);
  void placeScores(CEGUI::Window* display, std::string title, const int num1, const int num2);
  void createMenu();
  void createScoreboard();
  void createMultiplayerScoreboard();
  void destroyMenu();
  bool enteredHostName(const CEGUI::EventArgs &e);
  bool renderGame(const CEGUI::EventArgs &e);
  bool renderGameServer(const CEGUI::EventArgs &e);
  bool renderGameClient(const CEGUI::EventArgs &e);

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
};

#endif