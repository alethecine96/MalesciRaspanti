//
// Created by alessandro on 07/12/18.
//

#include "Observer.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


void Observer::Notify()
{
    for(int i=0; i<4; i++)
    {
        int a = array->at(i)->getPositionX();
        int b = array->at(i)->getPositionY();
        //std::cout<< "la posizione di " << i << " is " << a << "||" << b << std::endl;
    }
}

void Observer::Position_of_Player()
{
        int a = array->at(0)->getPositionX();
        int b = array->at(0)->getPositionY();
        //std::cout<< "la posizione di " << i << " is " << a << "||" << b << std::endl;
}
bool Observer::Collision()
{

    for(int i=1; i<4; i++)
    {
        int Player_x = array->at(0)->getPositionX();
        int Player_y = array->at(0)->getPositionY();
        int Enemy_x = array->at(i)->getPositionX();
        int Enemy_y = array->at(i)->getPositionY();

        for (int j= 0; j < 4; j++)
        {
            Player_x += pow(j, 2) * (-14) + 42 * j + 2;
            if (j == 0 || j == 1)
            {
                Player_y += 2;
            }
            if (j == 2 || j == 3)
            {
                Player_y += 30;
            }


            if(Player_x>=Enemy_x && Player_x<=Enemy_x+32)
            {
                if(Player_y>=Enemy_y && Player_y<=Enemy_y+32)
                {
                    //std::cout<<"COLLISIONE"<<std::endl;
                    return true;

                }
            }

        }
    }



}


