#include <iostream>
using namespace std;

#include "ParkingSystem.h"
#include "ParkingLot.h"

ParkingSystem::ParkingSystem(){
    *lotsArr = new ParkingLot[5];
    
}

ParkingSystem::~ParkingSystem(){
    delete [] lotsArr;
}

void ParkingSystem::createLot(int id, int rows, int columns){
    if (rows > 12 || columns > 12 || rows <= 0 || columns <= 0)
    {
        cout << "Row and column number should be in (0, 13) interval" << endl;
    }

    else{
        for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++){
            if (lotsArr[i]->getId() == id){
                cout << "The parking lot id is not unique" << endl;
                break;
            }

            if(lotsArr[i]->getId() == 0){
                lotsArr[i] = new ParkingLot(id, rows, columns);
                break;
            }
        
        }

        cout << "More than 5 Parking Lot cannot be created" << endl;
    }
    
}

void ParkingSystem::removeLot(int id){

}

void ParkingSystem::listLots(){

}

void ParkingSystem::lotContents(int id){

}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber){

}

void ParkingSystem::findCar(int plateNumber){

}

void ParkingSystem::removeCar(int plateNumber){

}