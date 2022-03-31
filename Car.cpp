#include <iostream>
using namespace std;

#include "Car.h"

Car::Car(int plateNumberInput, char typeInput){
    plateNumber = plateNumberInput;
    type = typeInput;
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