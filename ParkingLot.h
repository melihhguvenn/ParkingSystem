#ifndef __PARKINGLOT_H_
#define __PARKINGLOT_H_

#include <iostream>
#include "Car.h"

class ParkingLot{
public:
    ParkingLot();
    ParkingLot(int id, int rows, int columns);
    ~ParkingLot();
    int getId();
    int getRows();
    int getColumns();
    char** getLot();
    Car** getCars();
private: 
    int id;
    int rows;
    int columns;
    char** lot;
    Car** cars;
};

#endif