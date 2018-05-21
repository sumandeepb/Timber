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

    // Make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("assets/graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // Prepare the bee
    Texture textureBee;
    textureBee.loadFromFile("assets/graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    // Bee parameters
    bool beeActive = false;
    float beeSpeed = 0.0f;

    // Make cloud sprites
    Texture textureCloud;
    textureCloud.loadFromFile("assets/graphics/cloud.png");
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 150);
    spriteCloud3.setPosition(0, 300);

    // Cloud parameters
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    // Variable to control timing
    Clock clock;

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

        // Measure time
        Time dt = clock.restart();

        // Setup the bee
        if (!beeActive) {
            // Bee speed
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;

            // Bee height
            srand((int) time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);

            // switch bee movement on
            beeActive = true;
        } else {
            // move the bee
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

            // if bee has moved past the screen edge
            if (spriteBee.getPosition().x < -100) {
                // reset it to be a whole new bee next frame
                beeActive = false;
            }
        }

        // Manage the clouds
        // Cloud 1
        if (!cloud1Active) {
            // Cloud speed
            srand((int) time(0) * 10);
            cloud1Speed = (rand() % 200);

            // Cloud height
            srand((int) time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(-300, height);

            // switch bee movement on
            cloud1Active = true;
        } else {
            // move the cloud
            spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

            // if cloud has moved past the screen edge
            if (spriteCloud1.getPosition().x > 1920) {
                // reset it to be a whole new cloud next frame
                cloud1Active = false;
            }
        }

        // Cloud 2
        if (!cloud2Active) {
            // Cloud speed
            srand((int) time(0) * 20);
            cloud2Speed = (rand() % 200);

            // Cloud height
            srand((int) time(0) * 20);
            float height = (rand() % 300) - 150;
            spriteCloud2.setPosition(-300, height);

            // switch bee movement on
            cloud2Active = true;
        } else {
            // move the cloud
            spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);

            // if cloud has moved past the screen edge
            if (spriteCloud2.getPosition().x > 1920) {
                // reset it to be a whole new cloud next frame
                cloud2Active = false;
            }
        }

        // Cloud 3
        if (!cloud3Active) {
            // Cloud speed
            srand((int) time(0) * 30);
            cloud3Speed = (rand() % 200);

            // Cloud height
            srand((int) time(0) * 30);
            float height = (rand() % 450) - 150;
            spriteCloud3.setPosition(-300, height);

            // switch bee movement on
            cloud3Active = true;
        } else {
            // move the cloud
            spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);

            // if cloud has moved past the screen edge
            if (spriteCloud3.getPosition().x > 1920) {
                // reset it to be a whole new cloud next frame
                cloud3Active = false;
            }
        }

        /*
            Draw the scene
         */

        // Clear everything from last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // Draw the tree
        window.draw(spriteTree);

        // Draw the bee
        window.draw(spriteBee);

        // Show everything we just drew
        window.display();
    }

    return 0;
}

