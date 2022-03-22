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

void Car::setPlateNumber(int plate){
    plateNumber = plate;
}

int Car::getPlateNumber(){
    return plateNumber;
}

char Car::getType(){
    return type;
}