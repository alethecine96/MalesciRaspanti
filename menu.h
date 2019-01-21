//
// Created by francesco on 06/01/18.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu();
    ~Menu();


    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

    int start();

    int renderMap();



private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
};

#endif //PROJECT_MENU_H
