#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

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
         */
        void draw(SDL_Renderer* renderer, int x, int y);
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
