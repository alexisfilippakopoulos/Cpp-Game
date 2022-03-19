#include "graphics.h"
#include "SpaceWars.h"
#include "config.h"


void update(float ms)
{
    SpaceWars* game = reinterpret_cast<SpaceWars*>(graphics::getUserData());
    game->update();
}


void draw()
{
    SpaceWars* game = reinterpret_cast<SpaceWars*>(graphics::getUserData());
    game->draw();
}

int main()
{
    SpaceWars mygame;
  
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "SpaceWars");
    
    //graphics::setFullScreen(true);

    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    mygame.init();
    graphics::startMessageLoop();
    
    return 0;
}