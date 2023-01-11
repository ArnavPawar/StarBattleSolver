//
// Created by Arnav on 3/11/2022.
//
#include <iostream>   // library for reading & writing from the console/keyboard
#include <fstream>	  // accesses your hard drive
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "board.h"
#include "section.h"


int main(int argc,char** argv) {

    std::string input=argv[1];
    std::string output=argv[2];
    std::string starPerZone=argv[3];//number(CONVERT TO INT)
    std::string outputMode=argv[4];//count or print
    std::string solutionMode=argv[5];

    std::ifstream infile(input);//READING DATA
    std::ofstream outfile(output);//WRITING DATA

    if(!infile){
        std::cerr << "Could not open"<<argv[1]<<" to read\n";
        return 1;
    }
    if(!outfile){
        std::cerr << "Could not open"<<argv[2]<<" to write\n";
        return 1;
    }

    int ysize,xsize;
    int starPer=std::stoi(starPerZone);//converts the string to int

    infile>>ysize>>xsize;
    board newBoard(ysize,xsize,starPer);//creates board with x and y size

    int totalCount=0;

    std::string letterIdentity;
    int numOfSpots=0;

    //adds all of the data to a vector
    while(infile>>letterIdentity>>numOfSpots){
            section sector(letterIdentity,numOfSpots,starPer);
            totalCount+=numOfSpots;
            for(int i=0;i<numOfSpots;i++){
                int xCoor,yCoor;
                infile>>xCoor>>yCoor;
                std::vector<int> oneCoor={xCoor,yCoor};
                sector.addPoint(oneCoor);
            }
            newBoard.addSection(sector);
    }
    newBoard.startRec(outputMode,solutionMode,outfile);
    return 0;
}