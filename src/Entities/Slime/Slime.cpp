#include "Slime.h"
#include "Asset Headers/TextureManager.h"
#include <SDL2/SDL.h>

Slime::Slime():health(100),isAlive(true),dir(Direction::South){
    srcrect.w=GRIDSIZE;
    srcrect.h=GRIDSIZE;
    srcrect.x=0;
    srcrect.y=0;
    dstrect.w=slimeWidth;
    dstrect.h=slimeHeight;
    dstrect.x=100;
    dstrect.y=100;
}