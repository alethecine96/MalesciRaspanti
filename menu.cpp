//
// Created by francesco on 06/01/18.
//
#include "menu.h"
#include <iostream>

Menu::Menu()
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y),
                    "The Prisoner");

    // Load the background into the texture
    // Be sure to scale this image to your screen size
    backgroundTexture.loadFromFile("/home/alessandro/CLionProjects/menu/back.jpg");

    // Associate the sprite with the texture
    background.setTexture(backgroundTexture);


    if (!font.loadFromFile("/home/alessandro/CLionProjects/menu/arial.ttf"))
    {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(resolution.x / 2, resolution.y / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(resolution.x / 2, resolution.y / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(resolution.x / 2, resolution.y / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

int Menu::start(){
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (GetPressedItem())
                            {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    //funzione che crea la mappa (dentro map.cpp)
                                    window.close(); //con questa si chiude il menù dopo il play, ma poi chiudendo l'inventario si chiude anche la mappa
                                    renderMap();
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

            }
        }

        window.clear();

        draw(window);


        window.display();
    }

    return 0;

}


