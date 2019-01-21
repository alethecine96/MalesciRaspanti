//
// Created by alessandro on 21/11/18.
//

#ifndef PROJECT_DRAWABLE_H
#define PROJECT_DRAWABLE_H


#include <SFML/Graphics/Drawable.hpp>

class Drawable : public sf::Drawable {
public:
    int x;
    int y;


    virtual void move(int a, int b);
    virtual void move();
    virtual void move(int d);
    virtual void shoot();
    virtual int getPositionX();
    virtual int getPositionY();
    virtual int getDirection();

};


#endif //PROJECT_DRAWABLE_H
