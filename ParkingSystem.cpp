#include <iostream>
using namespace std;

#include "ParkingSystem.h"
#include "ParkingLot.h"

ParkingSystem::ParkingSystem(){
    *lotsArr = new ParkingLot[5];
}

ParkingSystem::~ParkingSystem(){
    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        delete [] lotsArr[i];
    }
    
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

        }

        for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
        {
            if(lotsArr[i]->getId() == 0){
                lotsArr[i] = new ParkingLot(id, rows, columns);
                break;
            }
            else{
                if (i == 4)
                {
                    cout << "No more than 5 lots can be created" << endl;
                }
                
            }
            
        }

        cout << "More than 5 Parking Lot cannot be created" << endl;
        
    }
    
}

void ParkingSystem::removeLot(int id){
}

void ParkingSystem::listLots(){
    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        cout << "ID: " << lotsArr[i]->getId() << "Dim: (" << lotsArr[i]->getRows() 
        << "," << lotsArr[i]->getColumns() << "), number of empty parking spaces: " 
        << lotsArr[i]->getRows() * lotsArr[i]->getColumns() << endl;
    }
    
}

void ParkingSystem::lotContents(int id){

}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber){
    char row = location[0];
    int rowAsInt;
    int columnsAsInt = location[1];
    char** wantedLot;
    Car** wantedCars;

    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        if (lotsArr[i]->getId() == lotId)
        {
            wantedLot = lotsArr[i]->getLot();
            wantedCars = lotsArr[i]->getCars();
            switch (row)
            {
                case 'A':
                    rowAsInt=0;
                    break;
                case 'B':
                    rowAsInt=1;
                    break;
                case 'C':
                    rowAsInt=2;
                    break;
                case 'D':
                    rowAsInt=3;
                    break;
                case 'E':
                    rowAsInt=4;
                    break;
                case 'F':
                    rowAsInt=5;
                    break;
                case 'G':
                    rowAsInt=6;
                    break;
                case 'H':
                    rowAsInt=7;
                    break;
                case 'I':
                    rowAsInt=8;
                    break;
                case 'J':
                    rowAsInt=9;
                    break;
                case 'K':
                    rowAsInt=10;
                    break;
                case 'L':
                    rowAsInt=11;
                    break;
            }

            if (carType == "a")
            {
                if(wantedLot[rowAsInt][columnsAsInt] == '+'){
                    lotsArr[i]->getCars()[rowAsInt][columnsAsInt].setPlateNumber(plateNumber);
                    lotsArr[i]->getLot()[rowAsInt][columnsAsInt] = 'a';
                    cout << "Light-duty car with number plate " << plateNumber 
                    << " has been parked at location " << location << ", lot" << lotId << endl;
                }
                else{
                    cout << "Cannot park light-duty car with number plate " << plateNumber 
                    << " at location " << location << ", not enough space" << endl;
                }
            }
                
            if (carType == "b")
            {
                if(rowAsInt != 0 || wantedLot[rowAsInt][columnsAsInt] == '+'){
                    if (wantedLot[rowAsInt - 1][columnsAsInt] == '+')
                    {
                        lotsArr[i]->getCars()[rowAsInt][columnsAsInt].setPlateNumber(plateNumber);
                        lotsArr[i]->getCars()[rowAsInt-1][columnsAsInt].setPlateNumber(plateNumber);
                        lotsArr[i]->getLot()[rowAsInt][columnsAsInt] = 'b';
                        lotsArr[i]->getLot()[rowAsInt-1][columnsAsInt] = 'b';
                        cout << "Heavy-duty car with number plate " << plateNumber 
                        << " has been parked at location " << location << ", lot" << lotId << endl;
                    }
                    else{
                        cout << "Cannot park heavy-duty car with number plate " << plateNumber 
                        << " at location " << location << ", not enough space" << endl;
                    }
                        
                }
                else{
                    cout << "Cannot park heavy-duty car with number plate " << plateNumber 
                    << " at location " << location << ", not enough space" << endl;
                }
            }
                
                
        }
            
    }
        
}

void ParkingSystem::findCar(int plateNumber){
    char rowsAsChar;
    for (int i = 0; i < sizeof(lotsArr)/sizeof(*lotsArr); i++)
    {
        for (int j = 0; j < lotsArr[i]->getRows(); j++)
        {
            for (int k = 0; k < lotsArr[i]->getColumns(); i++)
            {

                if (lotsArr[i]->getCars()[j][k].getPlateNumber() == plateNumber){
                    switch (j){
                        case 0:
                            rowsAsChar= 'A';
                            break;
                        case 1:
                            rowsAsChar= 'B';
                            break;
                        case 2:
                            rowsAsChar= 'C';
                            break;
                        case 3:
                            rowsAsChar= 'D';
                            break;
                        case 4:
                            rowsAsChar= 'E';
                            break;
                        case 5:
                            rowsAsChar= 'F';
                            break;
                        case 6:
                            rowsAsChar= 'G';
                            break;
                        case 7:
                            rowsAsChar= 'H';
                            break;
                        case 8:
                            rowsAsChar= 'I';
                            break;
                        case 9:
                            rowsAsChar= 'J';
                            break;
                        case 10:
                            rowsAsChar= 'K';
                            break;
                        case 11:
                            rowsAsChar= 'L';
                            break;
                    }

                    if (lotsArr[i]->getCars()[j][k].getType() == 'a')
                    {
                        cout << "Light-duty car with number plate " << plateNumber << " is at location " << rowsAsChar << k << ", lot " << lotsArr[i]->getId() << endl;
                    }
                    else{
                        cout << "Light-duty car with number plate " << plateNumber << " is at location " << rowsAsChar << k << ", lot " << lotsArr[i]->getId() << endl;
                    }
                }

                else{
                    cout << "The car with the number plate " << plateNumber << " is not in the system" << endl;
                }
            }    
            
        }
        
    }
    
}

void ParkingSystem::removeCar(int plateNumber){

}