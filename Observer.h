//
// Created by alessandro on 07/12/18.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <vector>
#include <list>
#include <array>
#include "Player.h"
#include "Drawable.h"

class Observer {
public:
    Observer(std::array<Drawable*,4> *array){
        this->array=array;
    }

    void Notify();
    bool Collision();
    void Position_of_Player();
private:
    std::array<Drawable*,4> *array;



};


#endif //PROJECT_OBSERVER_H
