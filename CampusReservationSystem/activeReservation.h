#ifndef ACTIVE_RESERVATION_H
#define ACTIVE_RESERVATION_H

#include "reservation.h"
// creating active reservation classs to reserve all link list
class ActiveReservation{
    private:
     // struct for nodes
    struct reservationNode
    {
        // store reservation and pointer to next node
        Reservation reservation;
        reservationNode* next;
// creating new nodes
        reservationNode(Reservation res)
        {
            reservation = res;
            next = nullptr;
        }
    };
    // pointer to the first node
    reservationNode* head;

    public:

    // Constructor
    ActiveReservation();
    // Add reservation,
    void addReservation(Reservation reservation);

    // Remove reservation 
    bool removeReservation(int reservationID);

    Reservation* findReservation(int reservationID);
    
    // Display all active reservations
    void displayReservations() const;

    // Destructor
    ~ActiveReservation();
};
#endif