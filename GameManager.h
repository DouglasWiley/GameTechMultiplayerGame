#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "BaseApplication.h"
#include "Game.h"
#include <sstream>
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

  int score;
  float time;
  bool soundOn;
  OgreBites::TextBox* scoreDisplay;
  OgreBites::TextBox* timerDisplay;
  OgreBites::TextBox* endDisplay;
  void placeIntInDisplay(OgreBites::TextBox*, const int num);

protected:
    virtual void createScene(void);
    virtual void createCamera();
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
};

#endif