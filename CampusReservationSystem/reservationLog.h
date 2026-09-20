#ifndef RESERVATION_LOG_H
#define RESERVATION_LOG_H

#include "reservation.h"
#include <stack>

//This function is intended to undo the most recent cancelled reservations

class ReservationLog{
    private:
        stack<Reservation> cancelledRes;

    public:
        ReservationLog();

        //Copies recent cancellations
        void copyCancel(const Reservation reservation);

        //True/False if cancellation can be undone
        bool canUndo() const;

        //Returns most recent cancelled reservation
        Reservation undoCancel();

        void displayLog() const;

};







#endif