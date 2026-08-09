#pragma once
//*World Tile Dimensions
constexpr int _TILEWIDTH=50;
constexpr int _TILEHEIGHT=50;

//* Player Frame Indicies and Sizes
constexpr int _FRAMESIZE = 48;
constexpr double _FRAMETIME = 0.2;
constexpr int playerWidth=150;
constexpr int playerHeight=90;
constexpr int idleSouthIndex=0;
constexpr int idleSidesIndex=1;
constexpr int idleNorthIndex=2;
constexpr int walkSouthIndex=3;
constexpr int walkSidesIndex=4;
constexpr int walkNorthIndex=5;
constexpr int attackSouthIndex=6;
constexpr int attackSidesIndex=7;
constexpr int attackNorthIndex=8;
constexpr int deathIndex=9;
constexpr int walkFrames = 6;
constexpr int attackFrames = 4;
constexpr int deathFrames=3;

//*Window Width And Height
constexpr int __ScreenWidth = 1280;
constexpr int __ScreenHeight = 720;