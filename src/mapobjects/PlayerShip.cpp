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

void PlayerShip::processInput() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        // Calculate velocity based on current angle of PlayerShip (converted from degrees to radians)
        applyForce(SPEED_CONST, _angle);
    }
    // Left thruster - accelerate to the right
    if (currentKeyStates[SDL_SCANCODE_L]) {
        applyForce(SPEED_CONST / 2, _angle + 90);
    }
    // Right thruster - accelerate to the left
    if (currentKeyStates[SDL_SCANCODE_K]) {
        applyForce(SPEED_CONST / 2, _angle - 90);
    }
    // Turn ship to the right
    if (currentKeyStates[SDL_SCANCODE_D]) {
        _angle += TURN_CONST;
    }
    // Turn ship to the right
    if (currentKeyStates[SDL_SCANCODE_A]) {
        _angle -= TURN_CONST;
    }
}

void PlayerShip::move() {
    _x += _xVel;
    _y -= _yVel;
}

void PlayerShip::applyForce(double force, double direction) {
    _yVel += force * cos(direction * radianConstant);
    _xVel += force * sin(direction * radianConstant);
}

