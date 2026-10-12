#include "reservation.h"
#include <iostream>
#include <iomanip>

Reservation::Reservation(){
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resourceID = 0;
    reservationDate = "";
    startTime= "";
    endTime ="";

    
}

Reservation::Reservation(int resID, int stuID, const string stuName, const int itemID, const string date, const string start, const string end){
    reservationID = resID;
    studentID = stuID;
    studentName = stuName;
    resourceID = itemID;
    reservationDate = date; 
    startTime = start;
    endTime = end;
}


int Reservation::getResID() const{
    return reservationID;
}

int Reservation::getStuID() const{
    return studentID;
}

string Reservation::getStuName() const{
    return studentName;
}

int Reservation::getItemID() const{
    return resourceID;
}
string Reservation::getDate() const{
    return reservationDate;
}

string Reservation :: getStartTime() const{
    return startTime;
}

string Reservation :: getEndTime() const{
    return endTime;
}


void Reservation::display() const{
    cout  << left << setw(18) << reservationID 
    << setw(10) << studentID 
    << setw(20) << studentName
     << setw(10) << resourceID 
     << setw(15) << reservationDate<< setw(12) << startTime << setw(12)<< endTime <<endl;
}
