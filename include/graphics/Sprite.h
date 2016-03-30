#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"

/**
 * This class represents sprites used in the game.
 * It contains a pointer to a sprite sheet and a rectangle
 * defining its position and size on the sprite sheet.
 */
class Sprite {
    public:

        /**
         * Constructor.
         * @param spriteSheet - The texture from which the sprite is rendered.
         * @param clip - The rectangle that defines the position and size of the sprite.
         * on the sprite sheet.
         */
        Sprite(SDL_Texture* spriteSheet, SDL_Rect clip);

        /**
         * Render the sprite. Does not affect the size of the sprite in any way.
         * @param renderer - The renderer that the sprite is rendered to.
         * @param x - The x position of the game window that the sprite will be rendered to.
         * @param y - The y position of the game window that the sprite will be rendered to.
         * @param angle - The number of degrees the sprite will be rotated from its original position.
         * @param center - The point specifying the center of rotation.
         * @param flip - Enum specifying if and how the sprite is flipped.
         */
        void draw(SDL_Renderer* renderer, int x, int y, double angle = 0.0, SDL_Point* center = nullptr,
                  SDL_RendererFlip flip = SDL_FLIP_NONE);

        /**
         * Render the sprite. Resizes the sprite according to the arguments of the method.
         * @param renderer - The renderer that the sprite is rendered to.
         * @param x - The x position of the game window that the sprite will be rendered to.
         * @param y - The y position of the game window that the sprite will be rendered to.
         * @param w - The width of the sprite when drawn to the screen.
         * @param h - The height of the sprite when drawn to the screen.
         * @param angle - The number of degrees the sprite will be rotated from its original position.
         * @param center - The point specifying the center of rotation.
         * @param flip - Enum specifying if and how the sprite is flipped.
         */
        void drawResized(SDL_Renderer* renderer, int x, int y, int w, int h, double angle = 0.0,
                         SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

        /**
         * Returns the relative center point of the sprite. In practice, this is the
         * sprite's width divided by 2 and the sprite's height divided by 2.
         */
        SDL_Point getCenter();

    private:

        /**
         * The texture from which the sprite is rendered.
         */
        SDL_Texture* _spriteSheet = nullptr;

        /**
         * The rectangle that defines the position and size of the sprite on the sprite sheet.
         */
        SDL_Rect _clip;
};

#endif // SPRITE_H
