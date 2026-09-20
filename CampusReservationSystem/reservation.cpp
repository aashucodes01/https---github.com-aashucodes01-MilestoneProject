#include "reservation.h"
#include <iostream>
#include <iomanip>

Reservation::Reservation(){
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resourceID = "";
    reservationDate = "";
    
}

Reservation::Reservation(int resID, int stuID, const string stuName, const string itemID, const string date){
    reservationID = resID;
    studentID = stuID;
    studentName = stuName;
    resourceID = itemID;
    reservationDate = date; 
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

string Reservation::getItemID() const{
    return resourceID;
}
string Reservation::getDate() const{
    return reservationDate;
}


void Reservation::display() const{
    cout  << left << setw(8) << reservationID << setw(10) << studentID << setw(20) << studentName << setw(10) << resourceID << setw(12) << reservationDate << endl;
}
