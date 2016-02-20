#include "PlayerShip.h"
#include <cmath>
#include <stdio.h>

#define PI 3.14159265
#define radianConstant PI / 180 // To convert degrees to radians

/* There seem to be some issues with this initialization. Are START_POS_X and Y set
   to 0 when the constructor is called or something? Haven't they been initialized properly yet?
   The ship spawns at (0,0) regardless of their value. */
PlayerShip::PlayerShip(Sprite* sprite) : MapObject(START_POS_X, START_POS_Y, sprite) {
}

PlayerShip::PlayerShip(int x, int y, Sprite* sprite) : MapObject(x, y, sprite) {
}

PlayerShip::~PlayerShip() {
}

void PlayerShip::processInput(SDL_Event& e) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        // Calculate velocity based on current angle of PlayerShip (converted from degrees to radians)
        _yVel = SPEED_CONST * cos(angle * radianConstant);
        _xVel = SPEED_CONST * sin(angle * radianConstant);
    } else {
        _xVel = 0;
        _yVel = 0;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        _direction += TURN_CONST;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        _direction -= TURN_CONST;
    }
}

void PlayerShip::move() {
    _x += _xVel;
    _y -= _yVel;
    angle = _direction;
}

