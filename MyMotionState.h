#ifndef __MyMotionState_h_
#define __MyMotionState_h_

#include <Ogre.h>
#include "btBulletDynamicsCommon.h"

class MyMotionState : public btMotionState {
public:
    MyMotionState(const btTransform &initialpos, Ogre::SceneNode *node);
    virtual ~MyMotionState();
    void setNode(Ogre::SceneNode *node);
    virtual void getWorldTransform(btTransform &worldTrans) const ;
    virtual void setWorldTransform(const btTransform &worldTrans);
    btTransform* getTransPointer();
protected:
    Ogre::SceneNode *mVisibleobj;
    btTransform mPos1;
};

#endif