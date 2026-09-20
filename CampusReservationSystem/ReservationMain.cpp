#include "ReservationMain.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


bool ReservationMain::loadFile(const string filename){
    ifstream file("reservations.txt");

    if (!file.is_open()){
        cout << "ERROR: Could not open reservations.txt" << endl;
        return false;
    }


} 

void ReservationMain::createReservation(int studentID, const string studentName, const string resourceID, const string date){

}







bool ReservationMain::cancelReservation(int reservationID){

}







bool ReservationMain::undoCancel(){
    
}





void ReservationMain::viewActiveReservations() const{

}