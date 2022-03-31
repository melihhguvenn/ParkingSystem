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
    void setId(int id);
    void setLot(char a, int rows, int columns);
private: 
    int idx;
    int rowsx;
    int columnsx;
    char** lot;
    Car** cars;
    char plus;
};

#endif