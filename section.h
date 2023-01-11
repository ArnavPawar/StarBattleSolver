//
// Created by Arnav on 3/11/2022.
//
#include <iostream>   // library for reading & writing from the console/keyboard
#include <fstream>	  // accesses your hard drive
#include <vector>

#ifndef DROPBOX_SECTION_H
#define DROPBOX_SECTION_H


class section {
public:
    section(std::string letter, int size_,int starPzone_) :let(letter) , size(size_),starPZone(starPzone_) {}

    void addPoint(std::vector<int> point);
    int getSize()const{return size;}
    int getStars()const{return countStars;}
    int getStarPZone()const{return starPZone;}
    std::string getName() const{return let;}

    bool hasPoint(const int x,const int y);//if that x and y coor is in the area 2d vector
    bool sectionFull();//check if countStar==star
    void adjustAddStar();//adds a star to this object
    void removeStar(int numOfStar);

    std::vector<int> getCoorGivenIndex(int index)const{return area[index];}//gives what coor at given index of zone

private:

    std::vector<std::vector<int>> area;
    std::string let;
    int size,starPZone;
    int countStars=0;
};

#endif //DROPBOX_SECTION_H
