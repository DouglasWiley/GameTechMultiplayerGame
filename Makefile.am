noinst_HEADERS = BaseApplication.h GameManager.h Game.h CollisionCallbacks.h Physics.h Room.h MyMotionState.h Ball.h Paddle.h NetManager.h

bin_PROGRAMS = assignment3
assignment3_CPPFLAGS = -I$(top_srcdir)
assignment3_SOURCES = NetManager.cpp BaseApplication.cpp Game.cpp GameManager.cpp Physics.cpp Room.cpp MyMotionState.cpp Ball.cpp Paddle.cpp
assignment3_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(CEGUI_CFLAGS)
assignment3_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS)
assignment3_LDFLAGS = -lOgreOverlay -lboost_system -lSDL -lSDL_mixer -lSDL_net -R/lusr/lib/cegui-0.8

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
