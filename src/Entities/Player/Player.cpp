#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Constants.h"
#include "Asset Headers/TextureManager.h"

Player::Player(): x(100.f),y(100.f),
                currentframe(0),animtimer(0.0)
{
    anim.rows=0;
    anim.frames=6;
    dstrect.w=playerWidth;
    dstrect.h=playerHeight;
    dstrect.x=static_cast<int>(x);
    dstrect.y=static_cast<int>(y);
    srcrect.w=_FRAMESIZE;
    srcrect.h=_FRAMESIZE;
    srcrect.x= currentframe * _FRAMESIZE;
    srcrect.y= anim.rows * _FRAMESIZE;
}


