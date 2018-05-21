/*
    Copyright 2018 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

/* 
 * File:   main.cpp
 * Author: sumandeep
 *
 * Created on 20 May, 2018, 12:30 AM
 */

#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/*
 * Timber : Replica of Timberman Steam Game
 */
int main(int argc, char** argv) {
    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    // Load a graphic into the texture
    textureBackground.loadFromFile("assets/graphics/background.png");

    // Create a sprite
    Sprite spriteBackground;

    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);

    // Set the sprite to cover the screen
    spriteBackground.setPosition(0, 0);

    while (window.isOpen()) {
        /*
            Handle the player input
         */
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        /*
            Update the scene
         */

        /*
            Draw the scene
         */
        // Clear everything from last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Show everything we just drew
        window.display();
    }

    return 0;
}

