//
// Created by alessandro on 12/09/18.
//

#include <iostream>
#include <cmath>
#include "Eyes.h"

bool Eyes::isWalkable(int x, int y,int direction) {

    int walkableTiles[] = {0, 58, 97};  //Tile Calpestabili
    int s = 3;

int oldX=x;
int oldY=y;
    for (int j = 0; j < 4; j++) {           //COLLISION!!

        x=oldX;
        y=oldY;

       x += pow(j, 2) * (-14) + 42 * j+2;
       if (j == 0 || j == 1)
            y += 2;
       if (j==2 || j==3)
           y += 30;
        int a = (x / 32);
        int b = (y / 32);
        bool walkable = false;
        for (int i = 0; i < s; i++) {
       //     std::cout << "in -  " << x << "-----" << y << "----" << mapArray[(b * 40) + a] << " --------  " << a << " || " << b << std::endl;

            if (mapArray[(b * this->width) + a] == walkableTiles[i])
                walkable = true;

        }

        if (!walkable)
            return false;
    }

    return true;

}
