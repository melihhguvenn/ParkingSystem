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
}

int ParkingLot::getId(){
    return id;
}