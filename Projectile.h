//
// Created by alessandro on 16/09/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Drawable.h"
#include "Eyes.h"

class Projectile : public Drawable {

public:
    int x,y;
    int speed;
    int direction;
    Eyes *eyes;
    Projectile(int x, int y, int speed, Eyes *eyes){
        this-> x=x;
        this-> y=y;
        this-> speed=speed;
        this-> eyes=eyes;

    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void move (int d);
    int getPositionX();
    int getPositionY();
};


#endif //PROJECT_PROJECTILE_H
