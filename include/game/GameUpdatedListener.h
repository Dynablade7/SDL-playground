#ifndef GAMEUPDATEDLISTENER_H
#define GAMEUPDATEDLISTENER_H

/**
 * Interface used to implement the Observer design pattern.
 * Any object that needs to be notified every time the game is changed in some way
 * should implement this interface.
 */
class GameUpdatedListener {
    public:
        virtual void GameUpdated() = 0;
};

#endif // GAMEUPDATEDLISTENER_H
