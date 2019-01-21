//
// Created by alessandro on 19/10/18.
//

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>
#include <SFML/System/Clock.hpp>
#include "Enemy.h"


void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Texture enemy_tileset;
    sf::VertexArray vertices(sf::Quads, 4);

    if (!enemy_tileset.loadFromFile("Guard.png"))   //TODO fare switch con prisoner e guard con relativi tileset
        return;

    vertices[0].position = sf::Vector2f(x, y+32);
    vertices[1].position = sf::Vector2f(x, y);
    vertices[2].position = sf::Vector2f(x+32, y);
    vertices[3].position = sf::Vector2f(x+32, y+32);

    // define its 4 texture coordinates
    vertices[0].texCoords = sf::Vector2f(0+step*32, 32+direction*32);
    vertices[1].texCoords = sf::Vector2f(0+step*32, 0+direction*32);
    vertices[2].texCoords = sf::Vector2f(32+step*32, 0+direction*32);
    vertices[3].texCoords = sf::Vector2f(32+step*32, 32+direction*32);

    target.draw(vertices, &enemy_tileset);

}


void Enemy::move() {

    int i=0;
    float l=4.5;
    if(i==rand()%20) {
        int v = rand() % 4;
        direction = v;
        return; // Enemy eredita da GameCharacter
    }


    int a= -pow(direction,3)+ l*pow(direction,2)-l*direction;
    int b= round(-0.6*direction+0.9);

    int j= this->x + this->speed*a;
    int k= this->y + this->speed*b;

    //std::cout << direction << "----" << j << "----" << k << std::endl;

    if(!(*this->eyes).isWalkable(j,k,direction))
        return;

    this->x=j;
    this->y=k;

    step=(step+1)%3;  //FIXME make me slower



}

int Enemy::getPositionX(){
    return x;
}

int Enemy::getPositionY(){
    return y;
}
