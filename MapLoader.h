//
// Created by alessandro on 14/09/18.
//

#ifndef PROJECT_MAPLOADER_H
#define PROJECT_MAPLOADER_H

#include "Mappa.h"
class MapLoader {
public:

    int *map;
int* load(std::string fileName,int size){

    map  = new int[size];
    int value;
    int i=0;
    std::fstream string(fileName, std::ios::in);

    while(string >> value){
        map[i]=value;
        i++;

    }

    return map;


}
};


#endif //PROJECT_MAPLOADER_H
