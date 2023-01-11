//
// Created by Arnav on 3/11/2022.
//
#include <iostream>   // library for reading & writing from the console/keyboard
#include <fstream>	  // accesses your hard drive
#include <vector>
#include "section.h"

#ifndef DROPBOX_BOARD_H
#define DROPBOX_BOARD_H


class board {
public:

    board(int ySize_, int xSize_,int starPer);

    std::vector<std::vector<std::string>> getCurChoice()const{return currentChoices;}

    void addSection(section Sector);

    int getX()const{return xSize;}
    char getY() const{return ySize;}
    int getNumOfZone()const{return allSections.size();}

    void setX(int X);//setter
    void setY(int Y);//setter

    void startRec(const std::string outputMode,const std::string solutionMode,std::ostream& os);
    void RecMain(int index,int whereInCoors,std::vector<std::vector<std::string>>& copyGrid,int &counter,std::vector<std::vector<std::vector<std::string>>> &allSolutions,std::string solutionMode);

    std::string findLetterFromCoors(int x, int y);//given coors tells what letter zone

    void printSolution(const std::vector<std::vector<std::string>> &inFuncCopy,std::ostream& os) ;//not const bc uses member func
    void printAllSolutions(const std::vector<std::vector<std::vector<std::string>>> &allSolutions,std::ostream& os) ;

    bool rowFull(const int y,const std::vector<std::vector<std::string>> &inFuncCopy);//checks if row full
    bool colFull(const int x,const std::vector<std::vector<std::string>> &inFuncCopy);//checks if col full
    bool win();//check if the final board is a win

    void updateSurround(const int x, const int y,std::vector<std::vector<std::string>> &inFuncCopy);//surround the coor with "x"'s
    void checkRowUpdate(const int y,std::vector<std::vector<std::string>> &inFuncCopy);//updates row if its full
    void checkColUpdate(const int x,std::vector<std::vector<std::string>> &inFuncCopy);//update col if full

    void updateWholeZoneifFull(int x, int y);

private:
    int xSize,ySize,starPZone;
    std::vector<section> allSections;
    std::vector<std::vector<std::string>> currentChoices;
};


#endif //DROPBOX_BOARD_H
