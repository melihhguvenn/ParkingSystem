#ifndef __CAR_H_
#define __CAR_H_

#include <iostream>
using namespace std;

class Car{
public:
    Car(int plateNumber, char type);
    Car();
    int getPlateNumber();
    void setPlateNumber(int plate);
    char getType();
private:
    int plateNumber;
    char type;
};

#endif