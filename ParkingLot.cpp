#include <iostream>
using namespace std;

#include "ParkingLot.h"

ParkingLot::ParkingLot(){
    id = 0;
    rows = 0;
    columns = 0;
}

ParkingLot::ParkingLot(int id, int rows, int columns){
    ParkingLot::id = id;
    ParkingLot::rows = rows;
    ParkingLot::columns = columns;

    //initialization of 2D array as pointer to pointer
    lot = new char* [rows];
    cars = new Car* [rows];

    for (int i = 0; i < rows; i++)
    {
        lot[i] = new char[columns];
        cars[i] = new Car[columns];

        for (int j = 0; j < columns; j++)
        {
            lot[i][j] = '+';
        }
        
    }
}

ParkingLot::~ParkingLot(){
    for (int i = 0; i < rows; i++)
    {
        delete [] lot[i];
        delete [] cars[i];
    }

    delete [] lot;
    delete [] cars;
}

int ParkingLot::getId(){
    return id;
}

int ParkingLot::getRows(){
    return rows;
}

int ParkingLot::getColumns(){
    return columns;
}

char** ParkingLot::getLot(){
    return lot;
}

Car** ParkingLot::getCars(){
    return cars;
}

void ParkingLot::setId(int id){
    ParkingLot::id = id;
}

void ParkingLot::setLot(char a, int rows, int columns){
    lot[rows][columns] = a;
}