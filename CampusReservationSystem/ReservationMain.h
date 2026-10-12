#ifndef RESERVATION_MAIN_H
#define RESERVATION_MAIN_H

#include <vector>
#include "reservation.h"
#include "waitingList.h"
#include "cancellationHistory.h"
#include "resource.h"
#include"activeReservation.h"
using namespace std;

class ReservationMain{
    private:
        ActiveReservation activeReservation;
        WaitingList waitList;
        CancellationHistory cancellationHistory;
        int nextReservationID;

         // stores the resource ID for each student request
        vector<int> requestedResourceIDs;

    public:
        ReservationMain();

        //Creates the reservation for user (FIFO order)
        void createReservation(int studentID, const string studentName, const int resourceID, const string date, const string startTime, const string endTime, vector<campusResource>& resources);

        //Cancels reservation by ID, removes from active reservation list
        bool cancelReservation(int reservationID, vector<campusResource>& resources);

    
        //Restores most recent cancelled reservations
        bool undoCancel(vector<campusResource>& resources);

        //searches reservations by reservationID, stuID, student name, resourceID, or date
        void viewActiveReservations() const;

        // searching reservation.
        void searchReservation(int reservationID);
    
        void viewWaitingList();

          // Display resources based on how many times they were requested.
        void showMostRequestedResources(vector<campusResource>& resources);

        // Display how many students are waiting for each resource.
        void showWaitingListStatistics(vector<campusResource>& resources);

};





#endif