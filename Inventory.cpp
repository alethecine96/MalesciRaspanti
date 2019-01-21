//
// Created by francesco on 09/01/18.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"

int TileMap::openInventory() {
    sf::RenderWindow window(sf::VideoMode(400, 225), "Inventory");

    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {

                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::E:

                            window.close();
                            break;
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}