//
// Created by alessandro on 16/09/18.
//


#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Projectile.h"
#include <cmath>
#include <iostream>

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Texture ammo_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!ammo_tileset.loadFromFile("ammo1.png"))
        return;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x+32, y);
    vertices[2].position = sf::Vector2f(x+32, y+32);
    vertices[3].position = sf::Vector2f(x, y+32);

    // define its 4 texture coordinates
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(32, 0);
    vertices[2].texCoords = sf::Vector2f(32, 32);
    vertices[3].texCoords = sf::Vector2f(0, 32);

    target.draw(vertices, &ammo_tileset);


}

void Projectile::move(int d) {

    float l=4.5;
    int a= -pow(d,3)+ l*pow(d,2)-l*d;
    int b= round(-0.6*d+0.9);

    int i = this->x + this->speed * a;
    int j = this->y + this->speed * b;

    this->x = i;
    this->y = j;

}

int Projectile::getPositionX(){
    return x;
}

int Projectile::getPositionY(){
    return y;
}





