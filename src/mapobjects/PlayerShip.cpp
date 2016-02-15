#include "PlayerShip.h"

PlayerShip::PlayerShip(Sprite* sprite) : MapObject(START_POS_X, START_POS_Y, sprite) {
}

PlayerShip::PlayerShip(int x, int y, Sprite* sprite) : MapObject(x, y, sprite) {
    //ctor
}

PlayerShip::~PlayerShip() {
    //dtor
}

void PlayerShip::processInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN /*&& e.key.repeat == 0*/) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: _y--; break;
            case SDLK_DOWN: _y++; break;
            case SDLK_LEFT: _x--; break;
            case SDLK_RIGHT: _x++; break;
        }
    }
}
