#include "Wall.h"

#include "GraphicsManager.h"
#include "WallHitbox.h"

Wall::Wall(int x, int y, Sprite* sprite) :
    MapObject(x, y, sprite) {
        generateHitboxes();
}

Wall::Wall(int x, int y, GraphicsManager* graphicsManager) :
    MapObject(x, y, graphicsManager->getSprite(SpriteEnum::GREEN_SQUARE)) {
        generateHitboxes();
}

Wall::~Wall() {
}

void Wall::generateHitboxes() {
    _hitboxes.push_back(new WallHitbox(_x, _y, -16, -16, 8));
    _hitboxes.push_back(new WallHitbox(_x, _y, -0, -16, 8));
    _hitboxes.push_back(new WallHitbox(_x, _y, -0, -0, 8));
    _hitboxes.push_back(new WallHitbox(_x, _y, -16, -0, 8));
}
