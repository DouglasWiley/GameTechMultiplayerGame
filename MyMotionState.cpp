#include "MyMotionState.h"
   
MyMotionState::MyMotionState(const btTransform &initialpos, Ogre::SceneNode *node) {
        mVisibleobj = node;
        mPos1 = initialpos;
}

MyMotionState::~MyMotionState() {}

void MyMotionState::setNode(Ogre::SceneNode *node) {
    mVisibleobj = node;
}
void MyMotionState::getWorldTransform(btTransform &worldTrans) const {
    worldTrans = mPos1;
}
void MyMotionState::setWorldTransform(const btTransform &worldTrans) {
    if(NULL == mVisibleobj) return; // silently return before we set a node
    btQuaternion rot = worldTrans.getRotation();
    mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
    btVector3 pos = worldTrans.getOrigin();
    // TODO **** XXX need to fix this up such that it renders properly since this doesnt know the scale of the node
    // also the getCube function returns a cube that isnt centered on Z
    mVisibleobj->setPosition(pos.x(), pos.y(), pos.z());
}
btTransform* MyMotionState::getTransPointer(){
    return &mPos1;
}