#include "PlayerShip.h"

#include "AttackHitbox.h"
#include "GraphicsManager.h"
#include "Hurtbox.h"
#include "SDL.h"

/* There seem to be some issues with this initialization. Are START_POS_X and Y set
   to 0 when the constructor is called or something? Haven't they been initialized properly yet?
   The ship spawns at (0,0) regardless of their value. */
PlayerShip::PlayerShip(Sprite* sprite) : MapObject(START_POS_X, START_POS_Y, sprite) {
    generateHitboxes();
}

PlayerShip::PlayerShip(int x, int y, Sprite* sprite) : MapObject(x, y, sprite) {
    generateHitboxes();
}

PlayerShip::PlayerShip(int x, int y, GraphicsManager* graphicsManager) :
    MapObject(x, y, graphicsManager->getSprite(SpriteEnum::TEST_SHIP)) {
        generateHitboxes();
}

void PlayerShip::processInput() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        // Calculate velocity based on current angle of PlayerShip (converted from degrees to radians)
        applyForce(SPEED_CONST, _direction);
    }
    // Left thruster - accelerate to the right
    if (currentKeyStates[SDL_SCANCODE_L]) {
        applyForce(SPEED_CONST / 2, _direction + 90);
    }
    // Right thruster - accelerate to the left
    if (currentKeyStates[SDL_SCANCODE_K]) {
        applyForce(SPEED_CONST / 2, _direction - 90);
    }
    // Turn ship clockwise
    if (currentKeyStates[SDL_SCANCODE_D]) {
        rotateDeg(TURN_CONST);
    }
    // Turn ship counter-clockwise
    if (currentKeyStates[SDL_SCANCODE_A]) {
        rotateDeg(-TURN_CONST);
    }
}

void PlayerShip::generateHitboxes() {
    Hurtbox* hb1 = new Hurtbox(_x, _y, -10, -10, 10);
    AttackHitbox* hb2 = new AttackHitbox(_x, _y, -5, -20, 5, 0, 1, 0);
    _hitboxes.push_back(hb1);
    _hitboxes.push_back(hb2);
}

