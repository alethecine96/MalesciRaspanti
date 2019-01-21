//
// Created by alessandro on 10/09/18.
//

#ifndef PROJECT_MAPPA_H
#define PROJECT_MAPPA_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <array>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>

class Mappa : public Drawable {
    // define the level with an array of tile indices
public:
    Mappa(std::array<Drawable*,4> *array,std::vector<Drawable*> *array1, int * m){
        this->array = array;
        my_array=m;
        this->array1 = array1;
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    int *my_array;
    std::array<Drawable*,4> *array;
    std::vector<Drawable*> *array1;
};


#endif //PROJECT_MAPPA_H
