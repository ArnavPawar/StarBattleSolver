//
// Created by Arnav on 3/11/2022.
//
#include <iostream>   // library for reading & writing from the console/keyboard
#include <fstream>	  // accesses your hard drive
#include <vector>
#include "board.h"
#include <string>
#include <cassert>
#include <algorithm>

board::board(int ySize_, int xSize_,int starPer){
     ySize=ySize_;
     xSize=xSize_;
     starPZone=starPer;
     currentChoices.resize(ySize,std::vector<std::string>(xSize,"."));
}

bool smallSize(section A,section B){
    return A.getSize() < B.getSize();
}

void board::addSection(section Sector){
    allSections.push_back(Sector);
    sort(allSections.begin(),allSections.end(),smallSize);
}

void board::setX(int X){//setter that decreases by one for both run loops
    xSize = X;
}
void board::setY(int Y){//setter that decreases by one for both run loops
    ySize = Y;
}

std::string board:: findLetterFromCoors(int x, int y){
    for(int i = 0; i<allSections.size();i++){
        if(allSections[i].hasPoint(x,y)){
            return allSections[i].getName();
        }
    }
    return "%";
}

void board::printSolution(const std::vector<std::vector<std::string>> &inFuncCopy,std::ostream& os) {
    os<<"Number of solutions: "<<"1"<<std::endl<<std::endl<<"Solution 1:"<<std::endl;
    for(int i=0; i<inFuncCopy.size();i++){//what row its in (i)
        for(int j=0;j<inFuncCopy[i].size();j++){//what col its in (j)

            if(inFuncCopy[i][j] == "." || inFuncCopy[i][j] == "X" ){
                os<<findLetterFromCoors(i,j);

            }
            else{
                os<<"@";
            }
            //std::cout<<currentChoices[i][j];
        }
        os<<std::endl;
    }
}
void board::printAllSolutions(const std::vector<std::vector<std::vector<std::string>>> &allSolutions,std::ostream& os){
    os<<"Number of solutions: "<<allSolutions.size()<<std::endl<<std::endl;
    for(int a=0;a<allSolutions.size();a++) {
        os<<"Solution "<<a+1<<":"<< std::endl;
        for (int i = 0; i < allSolutions[a].size(); i++) {//what row its in (i)
            for (int j = 0; j < allSolutions[a][i].size(); j++) {//what col its in (j)

                if (allSolutions[a][i][j] == "." || allSolutions[a][i][j] == "X") {
                    os << findLetterFromCoors(i, j);

                } else {
                    os << "@";
                }
                //std::cout<<currentChoices[i][j];
            }
            os << std::endl;
        }
        os<<std::endl;
    }
}

bool board::rowFull(const int y,const std::vector<std::vector<std::string>> &inFuncCopy){
    int count=0;
    for(int i=0; i<inFuncCopy[0].size();i++){
        if(inFuncCopy[y][i] == "@"){
            count++;
        }
        if(count ==  starPZone){
            return true;
        }
    }
    return false;
}
bool board::colFull(const int x,const std::vector<std::vector<std::string>> &inFuncCopy){
    int count=0;
    for(int i=0; i<inFuncCopy.size();i++){
        if(inFuncCopy[i][x] == "@"){
            count++;
        }
        if(count ==  starPZone){
            return true;
        }
    }
    return false;
}
bool board::win(){
    for(int i=0;i<allSections.size();i++){
        if(allSections[i].sectionFull()==false){
            return false;
        }
    }
    return true;
}

void board:: updateSurround(const int x, const int y,std::vector<std::vector<std::string>> &inFuncCopy){
    if(x==0 && y==0){
        inFuncCopy[y][x+1] ="X";
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x+1] ="X";
    }
    else if(x== getX()-1 and y==getY()-1){
        inFuncCopy[y][x-1] ="X";
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x-1] ="X";
    }
    else if(x==0 && y==getY()-1){
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x+1] ="X";
        inFuncCopy[y][x+1] ="X";
    }
    else if(x==getX()-1 && y==0){
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x-1] ="X";
        inFuncCopy[y][x-1] ="X";
    }
    else if(x==0){
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x+1] ="X";
        inFuncCopy[y][x+1] ="X";
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x+1] ="X";
    }
    else if(y==0){
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x+1] ="X";
        inFuncCopy[y+1][x-1] ="X";
        inFuncCopy[y][x-1] ="X";
        inFuncCopy[y][x+1] ="X";
    }
    else if(y==getY()-1){
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x+1] ="X";
        inFuncCopy[y-1][x-1] ="X";
        inFuncCopy[y][x-1] ="X";
        inFuncCopy[y][x+1] ="X";
    }
    else if(x==getX()-1){
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x-1] ="X";
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x-1] ="X";
        inFuncCopy[y][x-1] ="X";
    }
    else{
        inFuncCopy[y-1][x] ="X";
        inFuncCopy[y-1][x+1] ="X";
        inFuncCopy[y-1][x-1] ="X";
        inFuncCopy[y][x-1] ="X";
        inFuncCopy[y][x+1] ="X";
        inFuncCopy[y+1][x-1] ="X";
        inFuncCopy[y+1][x] ="X";
        inFuncCopy[y+1][x+1] ="X";
    }
}

void board::checkRowUpdate(const int y,std::vector<std::vector<std::string>> &inFuncCopy){
    if (rowFull(y,inFuncCopy) == true){
        for(int i=0; i<inFuncCopy[0].size();i++){
            if(inFuncCopy[y][i]!="@"){
                inFuncCopy[y][i] = "X";
            }
        }
    }
}
void board::checkColUpdate(const int x,std::vector<std::vector<std::string>> &inFuncCopy){
    if (colFull(x,inFuncCopy)==true){
        for(int i=0; i<inFuncCopy.size();i++){
            if(inFuncCopy[i][x]!="@"){
                inFuncCopy[i][x] = "X";
            }
        }
    }
};

void board::startRec(const std::string outputMode,const std::string solutionMode,std::ostream& os){
    int where=0;
    int index=0;
    int counter=0;

    std::vector<std::vector<std::vector<std::string>>> allSolutions;

    std::vector<std::vector<std::string>> copyOfAllChoices=currentChoices;//copy value so that it doesn't change member variable

    RecMain(index,where,copyOfAllChoices,counter,allSolutions,solutionMode);

    if(allSolutions.size() == 0){
        os<<"Number of solutions: 0";
    }
    else if(outputMode == "count"){
        os<<"Number of solutions: "<<allSolutions.size();
    }
    else if(outputMode == "print"){
        //print num and format of all solutions
        if(solutionMode=="one_solution"){
            printSolution(allSolutions[0],os);
        }
        else if(solutionMode=="all_solutions"){
            printAllSolutions(allSolutions,os);
        }
    }
}
//recursion only if it changes zones
void board::RecMain(int index,int whereInSec,std::vector<std::vector<std::string>>& copyGrid,int &counter,std::vector<std::vector<std::vector<std::string>>> &allSolutions, std::string solutionMode){//index of what zone, and index of what coordinate in zone

    std::vector<std::vector<std::string>> inFuncCopy=copyGrid;//only will be changed in each recursive call
    //if not at last zone
    if(solutionMode=="one_solution" && counter==1){//only one solution for time reasons
        return;
    }
    else if(index<allSections.size()){
        //while you there are still coors in the zone to loop thru
        while(whereInSec != allSections[index].getSize()) {
            if (inFuncCopy[allSections[index].getCoorGivenIndex(whereInSec)[1]][allSections[index].getCoorGivenIndex(whereInSec)[0]] == ".") {
                inFuncCopy[allSections[index].getCoorGivenIndex(whereInSec)[1]][allSections[index].getCoorGivenIndex(whereInSec)[0]] = "@";
                //update the x's on the current choices grid
                allSections[index].adjustAddStar();//adds a star to that zone object

                updateSurround(allSections[index].getCoorGivenIndex(whereInSec)[0],
                           allSections[index].getCoorGivenIndex(whereInSec)[1],inFuncCopy);
                checkColUpdate(allSections[index].getCoorGivenIndex(whereInSec)[0],inFuncCopy);
                checkRowUpdate(allSections[index].getCoorGivenIndex(whereInSec)[1],inFuncCopy);

                //if all the n vales are in the board move to next index(RECURSION)
                if (allSections[index].sectionFull()) {
                    if(win()){// check if each zone has n number of stars
                        allSolutions.push_back(inFuncCopy);
                        allSections[index].removeStar(1);
                        counter+=1;
                        inFuncCopy=copyGrid;//sets back to original
                        whereInSec++;
                        //finds solutions for all the other spots
                    }
                    //if no win and on last index of board then end and return
                    else{
                        RecMain(index + 1, 0,inFuncCopy,counter,allSolutions,solutionMode);
                        inFuncCopy=copyGrid;//sets back to original
                        allSections[index].removeStar(1);
                        //sets the given location to an X and moves on
                        inFuncCopy[allSections[index].getCoorGivenIndex(whereInSec)[1]][allSections[index].getCoorGivenIndex(whereInSec)[0]] = "X";
                    }
                    //deletes star and repeats the recursion
                }
                else{
                    RecMain(index , whereInSec++,inFuncCopy,counter,allSolutions,solutionMode);

                    allSections[index].removeStar(1);
                    inFuncCopy=copyGrid;//sets back to original
                }
            }
            else {
                whereInSec++;
            }
        }
        return;
    }
}
