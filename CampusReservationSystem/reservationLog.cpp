#include "reservationLog.h"
#include <iostream>

ReservationLog::ReservationLog(){}

void ReservationLog::copyCancel(const Reservation reservation){
    cancelledRes.push(reservation);
}

bool ReservationLog::canUndo() const{
    return !cancelledRes.empty();
}

Reservation ReservationLog::undoCancel(){
    Reservation recent = cancelledRes.top();
    cancelledRes.pop();
    return recent;
}

void ReservationLog::displayLog() const{
    if (cancelledRes.empty()){
        cout << "No recent cancellations." << endl;
        return;
    }

    stack<Reservation> copy = cancelledRes;
    cout << "Cancellation history:" << endl;

    while (!copy.empty()){
        copy.top().display();
        copy.pop();
    }
}