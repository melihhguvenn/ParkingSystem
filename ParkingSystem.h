#ifndef __PARKINGSYSTEM_H_
#define __PARKINGSYSTEM_H_

#include <iostream>
#include "ParkingLot.h"
using namespace std;

class ParkingSystem{
public:
    ParkingSystem();
    ~ParkingSystem();
    void createLot(int id, int rows, int columns);
    void removeLot(int id);
    void listLots();
    void lotContents(int id);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar(int plateNumber);
    ParkingLot** getLotsArr();
private:
    ParkingLot** lotsArr;
};

#endif