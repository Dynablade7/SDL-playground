#include "PlayerShip.h"

PlayerShip::PlayerShip(Sprite* sprite) : MapObject(START_POS_X, START_POS_Y, sprite) {
}

PlayerShip::PlayerShip(int x, int y, Sprite* sprite) : MapObject(x, y, sprite) {
}

PlayerShip::~PlayerShip() {
    //dtor
}

void PlayerShip::processInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: _y -= _yVelocity; break;
            case SDLK_DOWN: _y += _yVelocity; break;
            case SDLK_LEFT: _x -= _xVelocity; break;
            case SDLK_RIGHT: _x += _xVelocity; break;
        }
    }
}
