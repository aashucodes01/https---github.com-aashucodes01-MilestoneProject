#ifndef RESERVATION_MAIN_H
#define RESERVATION_MAIN_H

#include <vector>
#include "reservation.h"
#include "queue.h"
#include "reservationLog.h"
#include "resource.h"
using namespace std;

class ReservationMain{
    private:
        vector<Reservation> reservations;
        

        campusResource campusResource;
        waitList waitList;
        ReservationLog reservationLog;

    public:
        ReservationMain(campusResource campRes, waitList list, ReservationLog log);


        //loads reservations.txt
        bool loadFile(const string filename);

        //Creates the reservation for user (FIFO order)
        void createReservation(int studentID, const string studentName, const string resourceID, const string date);

        //Cancels reservation by ID, removes from active reservation list
        bool cancelReservation(int reservationID);

    
        //Restores most recent cancelled reservations
        bool undoCancel();

        //searches reservations by reservationID, stuID, student name, resourceID, or date
        void viewActiveReservations() const;

        

}





#endif