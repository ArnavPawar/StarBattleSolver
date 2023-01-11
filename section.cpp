//
// Created by Arnav on 3/11/2022.
//
#include <iostream>   // library for reading & writing from the console/keyboard
#include <fstream>	  // accesses your hard drive
#include <vector>
#include "section.h"


void section::addPoint(std::vector<int> point){
    area.push_back(point);
}

bool section::hasPoint(int x,int y){
    for(int i=0;i<area.size();i++){
        if((area[i][0] == y) && (area[i][1] == x)){
            return true;
        }
    }
    return false;
}

void section:: adjustAddStar(){
    countStars+=1;
}

void section::removeStar(int numOfStar) {
    countStars-=numOfStar;
}

bool section:: sectionFull(){
    if(countStars==starPZone){
        return true;
    }
    return false;
}
