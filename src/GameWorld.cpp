/**
 * @file GameWorld.cpp
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld class implementation.
 * 
 * @copyright Copyright (c) 2026
 */
#include <iostream>
#include <string>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "raylib/raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

/**
 * @brief Construct a new GameWorld object
 */
GameWorld::GameWorld() {
    // initializing the player ( I still don't understand how to do that with constructors D: )
    player.position.x = 100;
    player.position.y = 100;
    player.width = 100;
    player.height = 100;
    player.color = GREEN;
    player.velocity.x = 0;
    player.velocity.y = 0;
};

/**
 * @brief Destroy the GameWorld object
 */
GameWorld::~GameWorld() = default;

/**
 * @brief Reads user input and updates the state of the game.
 */
void GameWorld::update( float delta ) {

    player.update( delta );

}

/**
 * @brief Draws the state of the game.
 */
void GameWorld::draw() {

    BeginDrawing();

    ClearBackground( WHITE );

    player.draw();

    DrawFPS( 20, 20 );

    EndDrawing();

}

/**
 * @brief Load game resources like images, textures, sounds, fonts, shaders,
 * etc. It will be called in Game Window after the creation of the Raylib
 * window.
 */
void GameWorld::loadResources() {
    ResourceManager::loadResources();
}

/**
 * @brief Unload the once loaded game resources. It will be called
 * after the game loop ends.
 */
void GameWorld::unloadResources() {
    ResourceManager::unloadResources();
}