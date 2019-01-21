//
// Created by alessandro on 19/10/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <iostream>
#include <array>
#include "Player.h"
#include "Drawable.h"


class Enemy : public Drawable {
public:
    int y;
    int x;
    int speed;
    int direction;
    int step;
    Eyes *eyes;


    Enemy(int x,int y, int speed, Eyes *eyes){
        this->x=x;
        this->y=y;
        this->speed=speed;
        direction=0;
        step=0;//FIXME enum
        this->eyes = eyes;
    };


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual int  getPositionX();
    virtual int  getPositionY();



    void move();

};


#endif //PROJECT_ENEMY_H