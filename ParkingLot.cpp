#include <iostream>
using namespace std;

#include "ParkingLot.h"

ParkingLot::ParkingLot(){
    idx = 0;
    rowsx = 0;
    columnsx = 0;
}

ParkingLot::ParkingLot(int id, int rows, int columns){
    idx = id;
    rowsx = rows;
    columnsx = columns;
    plus = '+';

    //initialization of 2D array as pointer to pointer
    lot = new char* [rows];
    cars = new Car* [rows];

    for (int i = 0; i < rows; i++)
    {
        lot[i] = new char[columns];
        cars[i] = new Car[columns];

        for (int j = 0; j < columns; j++)
        {
            lot[i][j] = plus;
        }
        
    }
}

ParkingLot::~ParkingLot(){
    for (int i = 0; i < rowsx; i++)
    {
        delete [] lot[i];
        delete [] cars[i];
    }

    delete [] lot;
    delete [] cars;
}

int ParkingLot::getId(){
    return idx;
}

int ParkingLot::getRows(){
    return rowsx;
}

int ParkingLot::getColumns(){
    return columnsx;
}

char** ParkingLot::getLot(){
    return lot;
}

Car** ParkingLot::getCars(){
    return cars;
}

void ParkingLot::setId(int id){
    idx = id;
}

void ParkingLot::setLot(char a, int rows, int columns){
    lot[rows][columns] = a;
}