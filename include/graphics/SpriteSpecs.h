#ifndef SPRITESPECS_H_INCLUDED
#define SPRITESPECS_H_INCLUDED

#include <iostream>
#include "SDL.h"
#include "Sprite.h"


/*
    ---------------------------------------------------------------------------------------
    This file contains all the metadata needed for sprites to be created,
    namely their position on the sprite sheet and their size.It needs to be hard-coded somewhere,
    I decided to put it all here. See SpriteSpecs.cpp for implementation.

    NOTE: At the moment there is only support for one single sprite sheet, which is declared
    in the GraphicsManager class. This is a fully functional solution, but as the project grows
    I might want to separate different kinds of sprites into different sheets. If so, there will
    need to be some structural changes.
    ---------------------------------------------------------------------------------------
*/

/**
 * Enum class with members representing the sprites of the game.
 */
enum class SpriteEnum{RED_SQUARE, GREEN_SQUARE, TEST_SHIP};

/**
 * Generates a Sprite depending on what SriteEnum is given as argument.
 * If a Sprite for that SpriteEnum is not yet defined in the method, a warning will be
 * printed and nullptr will be returned.
 * @param spriteEnum - The SpriteEnum corresponding to the wanted Sprite.
 * @param spriteSheet - The sprite sheet were the sprites are found.
 */
Sprite* generateSprite(SpriteEnum spriteEnum, SDL_Texture* spriteSheet);

#endif // SPRITESPECS_H_INCLUDED
