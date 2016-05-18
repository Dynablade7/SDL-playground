#include <iostream>
#include "MainGame.h"

/*
 * ---- DESIGN OVERVIEW ----
 * The main function creates a MainGame instance and starts the game by calling
 * its run method. The run method will loop until the user requests to quit. The process
 * returns once the run method returns.
 *
 * The game consists of a number of MapObjects that interract with each other.
 * One of them is controlled by the player. A CollisionManager object will check if
 * any MapObjects are colliding. In order to to this, each MapObject has a number
 * of Hitbox objects attatched to them - these are esentially circles with different attributes.
 * When hitboxes overlap, there is a collision, and action is taken depedning on the types of
 * the colliding hitboxes.
 */


int main(int argc, char** argv) {
    MainGame game;
    game.run();
    return 0;

}
