#ifndef __PARKINGLOT_H_
#define __PARKINGLOT_H_

#include <iostream>

class ParkingLot{
public:
    ParkingLot();
    ParkingLot(int id, int rows, int columns);
    int getId();
    int getRows();
    int getColumns();
private: 
    int id;
    int rows;
    int columns;
    char** lot;
};

#endif