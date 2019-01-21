//
// Created by alessandro on 12/09/18.
//

#ifndef PROJECT_EYES_H
#define PROJECT_EYES_H


class Eyes {

public:
    Eyes(int *mapArray,int width){
    this->mapArray = mapArray;
    this->width = width;
    }
    bool isWalkable(int x, int y,int direction);


private:
    int *mapArray;
    int width;


};
#endif //PROJECT_EYES_H
