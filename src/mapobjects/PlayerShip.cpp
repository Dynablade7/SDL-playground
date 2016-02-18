#include "PlayerShip.h"
#include <stdio.h>

PlayerShip::PlayerShip(Sprite* sprite) : MapObject(START_POS_X, START_POS_Y, sprite) {
}

PlayerShip::PlayerShip(int x, int y, Sprite* sprite) : MapObject(x, y, sprite) {
}

PlayerShip::~PlayerShip() {
}

void PlayerShip::processInput(SDL_Event& e) {
    // Check for pressed keys
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: _yVel -= VEL_CONST; break;
            case SDLK_DOWN: _yVel += VEL_CONST; break;
            case SDLK_LEFT: _xVel -= VEL_CONST; break;
            case SDLK_RIGHT: _xVel += VEL_CONST; break;
        }
    // Check for released keys, reset values
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: _yVel += VEL_CONST; break;
            case SDLK_DOWN: _yVel -= VEL_CONST; break;
            case SDLK_LEFT: _xVel += VEL_CONST; break;
            case SDLK_RIGHT: _xVel -= VEL_CONST; break;
        }
    }
}

void PlayerShip::move() {
    _x += _xVel;
    _y += _yVel;
}

