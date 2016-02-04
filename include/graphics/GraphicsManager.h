#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include "GameUpdatedListener.h"
#include "Sprite.h"

enum class SpriteEnum{RED_SQUARE, GREEN_SQUARE, TEST_SHIP};

class GraphicsManager : public GameUpdatedListener {
    public:
        /**
         * Destructor.
         */
        ~GraphicsManager();

        /**
         * Creates the window, renderer and texture.
         */
        void initGraphics();

        /**
         * Method derived from GameUpdatedListener.
         * This method is called whenever the game is updated and the screen needs to
         * be redrawn. Utilizing the Observer design pattern.
         */
        void GameUpdated();

        /**
         * Returns a pointer to the Sprite corresponding to the SpriteEnum given
         * as argument. If there is no Sprite defined for that SpriteEnum in generateSprite(),
         * nullptr is returned.
         * @param spriteEnum - The SpriteEnum corresponding to the wanted Sprite.
         */
        Sprite* getSprite(SpriteEnum spriteEnum);

    private:
        /**
         * The width/height of the game window.
         */
        const int SCREEN_WIDTH = 768, SCREEN_HEIGHT = 480;
        SDL_Window* _gameWindow = nullptr;
        SDL_Renderer* _renderer = nullptr;
        SDL_Texture* _mainTexture = nullptr;
        SDL_Texture* _spriteSheet = nullptr;
        SDL_Texture* _texture = nullptr;

        /**
         * Loads an SDL_Texture from an imamge file and returns a pointer to it.
         * @param path - The path to the image file.
         */
        SDL_Texture* loadTexture(std::string path);
        SDL_Rect clip;

        /**
         * A mapping of SpriteEnum to Sprite objects. Used when accessing sprites.
         */
        std::map<SpriteEnum, Sprite*> spriteMap;

        /**
         * Generates a Sprite depending on what SriteEnum is given as argument.
         * If a Sprite for that SpriteEnum is not yet defined in the method, a warning will be
         * printed and nullptr will be returned.
         * @param spriteEnum - The SpriteEnum corresponding to the wanted Sprite.
         */
        Sprite* generateSprite(SpriteEnum spriteEnum);


};

#endif // GRAPHICSMANAGER_H
