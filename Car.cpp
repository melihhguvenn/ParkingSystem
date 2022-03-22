#include <iostream>
using namespace std;

#include "Car.h"

Car::Car(int plateNumber, char type){
    Car::plateNumber = plateNumber;
    Car::type = type;
}

Car::Car(){
    plateNumber = 0;
    type = '+';
}

void Car::setPlateNumber(int& plate){
    plateNumber = plate;
}