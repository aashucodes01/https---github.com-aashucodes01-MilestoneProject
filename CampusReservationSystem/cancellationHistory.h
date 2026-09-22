<<<<<<< HEAD
#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include "reservation.h"
#include <stack>
using namespace std;

//This function is intended to undo the most recent cancelled reservations

//this class stores cancelled reservation
class CancellationHistory{
    private:
    // Last In first out applied
        stack<Reservation> cancelledRes;

    public:
        CancellationHistory();

        //Copies recent cancellations
        void copyCancel(const Reservation reservation);

        //True/False if cancellation can be undone
        bool canUndo() const;

        //Returns most recent cancelled reservation
        Reservation undoCancel();

        void displayLog() const;

};







=======
#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include "reservation.h"
#include <stack>
using namespace std;

//This function is intended to undo the most recent cancelled reservations

//this class stores cancelled reservation
class CancellationHistory{
    private:
    // Last In first out applied
        stack<Reservation> cancelledRes;

    public:
        CancellationHistory();

        //Copies recent cancellations
        void copyCancel(const Reservation reservation);

        //True/False if cancellation can be undone
        bool canUndo() const;

        //Returns most recent cancelled reservation
        Reservation undoCancel();

        void displayLog() const;

};







>>>>>>> c6303a74d491eda37866b4edfed7ac53c19c4bc9
#endif