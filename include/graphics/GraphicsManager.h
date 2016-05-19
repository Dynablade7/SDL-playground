#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <iostream>
#include <map>
#include <vector>
#include "GameUpdatedListener.h"
#include "SDL.h"
#include "SpriteSpecs.h"

// Forward declarations
class MapObject;
class Sprite;

/**
 * Class responsible for everything graphics related.
 * This includes loading images as Sprite objects, creating
 * a game window and rendering to it, and more.
 */
class GraphicsManager : public GameUpdatedListener {

    public:
        /**
         * Constructor.
         * @param mapObjects - A pointer to a vector containing all MapObjects to be drawn.
         */
        GraphicsManager(std::vector<MapObject*>* mapObjects);

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
        SDL_Texture* _spriteSheet = nullptr;

        /**
         * Loads an SDL_Texture from an imamge file and returns a pointer to it.
         * @param path - The path to the image file.
         */
        SDL_Texture* loadTexture(std::string path);

        /**
         * A mapping of SpriteEnum to Sprite objects. Used when accessing sprites.
         */
        std::map<SpriteEnum, Sprite*> spriteMap;

        /**
         * A vector of all MapObjects in the game.
         */
        std::vector<MapObject*>* _mapObjects = nullptr;
};

#endif // GRAPHICSMANAGER_H
