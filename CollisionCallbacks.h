#ifndef __COLLISION_CALLBACKS_H__
#define __COLLISION_CALLBACKS_H__

#include "btBulletDynamicsCommon.h"
#include "SDL/SDL_mixer.h"

struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
{
    MyContactResultCallback(int* scorePtr, float* timePtr, bool* soundOn) : context(scorePtr) , currentTimePtr(timePtr)
     , lastTimeSeen(*timePtr), soundOn(soundOn){
      collisionSound = Mix_LoadWAV("music/party.wav");
    }
    btScalar addSingleResult(btManifoldPoint& cp,
        const btCollisionObjectWrapper* colObj0Wrap,
        int partId0,
        int index0,
        const btCollisionObjectWrapper* colObj1Wrap,
        int partId1,
        int index1)
    {
      if(lastTimeSeen - *currentTimePtr > 1){
          (*context) += 10;
          lastTimeSeen = *currentTimePtr;
          if(*soundOn)
            Mix_PlayChannel(-1, collisionSound, 0);
        }
        // your callback code here
    }
    int* context;
    float* currentTimePtr;
    float lastTimeSeen;
    Mix_Chunk* collisionSound;
    bool* soundOn;
};

struct MyCollisionCallback : public btCollisionWorld::ContactResultCallback
{
    MyCollisionCallback(float* timePtr, char* soundName, bool* soundOn) : currentTimePtr(timePtr), lastTimeSeen(*timePtr), soundOn(soundOn){
      collisionSound = Mix_LoadWAV(soundName);
    }
    btScalar addSingleResult(btManifoldPoint& cp,
        const btCollisionObjectWrapper* colObj0Wrap,
        int partId0,
        int index0,
        const btCollisionObjectWrapper* colObj1Wrap,
        int partId1,
        int index1)
    {
      if(lastTimeSeen - *currentTimePtr > 1){
          lastTimeSeen = *currentTimePtr;
          if(*soundOn)
            Mix_PlayChannel(-1, collisionSound, 0);
        }
        // your callback code here
    }
    float* currentTimePtr;
    float lastTimeSeen;
    Mix_Chunk* collisionSound;
    bool* soundOn;
};

#endif
