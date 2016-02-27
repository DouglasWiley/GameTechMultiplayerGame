#ifndef __Ball_h_
#define __Ball_h_

#include "Physics.h"
#include <Ogre.h>
#include "MyMotionState.h"

#define BALL_SCALE 0.3f

class Ball{

public:
	Ball(Ogre::SceneManager*, Physics*);
	~Ball();
	
};

#endif