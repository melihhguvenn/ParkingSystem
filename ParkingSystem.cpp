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
        cout << "Cannot create parking lot " << id << ", dimensions exceed acceptable bounds" << endl;
    }

    else{
        for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++){
            if (lotsArr[i]->getId() == id){
                cout << "Cannot create parking lot" << id << ", a lot with this ID already exists" << endl;
                break;
            }

        }

        for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
        {
            if(lotsArr[i]->getId() == 0){
                lotsArr[i] = new ParkingLot(id, rows, columns);
                cout << "Parking lot with ID " << id << " and dimensions (" << rows << "," << columns << ") has been added to the system" << endl;
                break;
            }
            
        }
        
    }
    
}

void ParkingSystem::removeLot(int id){
    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        if (lotsArr[i]->getId() == id)
        {
            lotsArr[i]->setId(0);
            cout << "Lot " << id << " has been succesfully removed from the system" << endl;
        }
        else
        {
            cout << "Lot " << id << " is not in the system" << endl;
        }
        
    }
}

void ParkingSystem::listLots(){
    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        cout << "ID: " << lotsArr[i]->getId() << " Dim: (" << lotsArr[i]->getRows() 
        << "," << lotsArr[i]->getColumns() << "), number of empty parking spaces: " 
        << lotsArr[i]->getRows() * lotsArr[i]->getColumns() << endl;
    }
    
}

void ParkingSystem::lotContents(int id){
    int empty;
    int* parkedCars;
    int index = 0;
    int lot;
    char rowsAsChar;
    parkedCars = new int[5];

    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        if (lotsArr[i]->getId() == id)
        {
            lot = i;
            for (int j = 0; j < lotsArr[i]->getRows(); j++)
            {
                for(int k = 0; k < lotsArr[i]->getColumns(); k++)
                {
                    if(lotsArr[i]->getLot()[j][k] == '+'){
                        empty++;
                    }
                    else if(lotsArr[i]->getLot()[j][k] == 'a'){
                        parkedCars[index] = lotsArr[i]->getCars()[j][k].getPlateNumber();
                        index++;
                    }
                    else{
                        if (j > 0 && lotsArr[i]->getLot()[j][k] == 'b')
                        {
                            if (lotsArr[i]->getCars()[j-1][k].getPlateNumber()==
                            lotsArr[i]->getCars()[j][k].getPlateNumber() )
                            {
                                parkedCars[index] = lotsArr[i]->getCars()[j][k].getPlateNumber();
                                index++;
                            }
                            
                        }
                        
                    }
                }
            }
            
        }
    }

    cout << "ID: " << id << ", (" << lotsArr[lot]->getRows() << "," 
    << lotsArr[lot]->getColumns()<< "), empty slots: " << empty << ", parked cars: ";

    for (int i = 0; i < sizeof(parkedCars)/sizeof(*parkedCars); i++)
    {
        cout << parkedCars[i];
    }

    cout << endl;
    

    for (int i = 0; i < lotsArr[lot]->getRows() + 1; i++)
    {
        if(i == 0){
            cout << " ";
            for (int j = 0; j < lotsArr[lot]->getColumns(); j++)
            {
                cout << j;
            }
            cout << endl;
            continue;
        }
        switch (i - 1){
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
        cout << rowsAsChar;
        for ( int j = 0; j < lotsArr[lot]->getColumns(); j++)
        {
            cout << lotsArr[lot]->getLot()[i-1][j];
        }
        cout << endl;
    }
    
    delete [] parkedCars;
    
}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber){
    char row = (char) location[0];
    int rowAsInt;
    int columnsAsInt = (int)location[1];

    for (int i = 0; i < (sizeof(lotsArr)/sizeof(*lotsArr)); i++)
    {
        if (lotsArr[i]->getId() == lotId)
        {
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
                if(lotsArr[i]->getLot()[rowAsInt][columnsAsInt] == '+'){
                    lotsArr[i]->getCars()[rowAsInt][columnsAsInt].setPlateNumber(plateNumber);
                    lotsArr[i]->setLot('a', rowAsInt, columnsAsInt);
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
                if(rowAsInt != 0 || lotsArr[i]->getLot()[rowAsInt][columnsAsInt] == '+'){
                    if (lotsArr[i]->getLot()[rowAsInt - 1][columnsAsInt] == '+')
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
                        cout << "Heavy-duty car with number plate " << plateNumber << " is at location " << rowsAsChar << k << ", lot " << lotsArr[i]->getId() << endl;
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
                        lotsArr[i]->getLot()[j][k] = '+';
                        lotsArr[i]->getCars()[j][k].setPlateNumber(0);
                        cout << "Light-duty car with number plate " << plateNumber << " has been removed from the slot " << rowsAsChar << k << ", lot " << lotsArr[i]->getId() << endl;
                    }
                    else{
                        if (j < 11 && lotsArr[i]->getCars()[j+1][k].getPlateNumber() == plateNumber)
                        {
                            lotsArr[i]->getLot()[j][k] = '+';
                            lotsArr[i]->getLot()[j+1][k] = '+';
                            lotsArr[i]->getCars()[j][k].setPlateNumber(0);
                            lotsArr[i]->getCars()[j+1][k].setPlateNumber(0);
                        }
                        else if (j > 0 && lotsArr[i]->getCars()[j-1][k].getPlateNumber() == plateNumber)
                        {
                            lotsArr[i]->getLot()[j][k] = '+';
                            lotsArr[i]->getLot()[j-1][k] = '+';
                            lotsArr[i]->getCars()[j][k].setPlateNumber(0);
                            lotsArr[i]->getCars()[j-1][k].setPlateNumber(0);
                        }
                        
                        cout << "Heavy-duty car with number plate " << plateNumber << " has been removed from the slot " << rowsAsChar << k << ", lot " << lotsArr[i]->getId() << endl;
                    }
                }

                else{
                    cout << "The car with the number plate " << plateNumber << " is not in the system" << endl;
                }
            }    
            
        }
        
    }
}