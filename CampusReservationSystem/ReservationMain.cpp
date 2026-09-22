#include "ReservationMain.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// constructor..
ReservationMain::ReservationMain()
{
    // First reservation ID starts at 1
    nextReservationID = 1;
}

// function to create reservation.
void ReservationMain::createReservation(const int studentID, const string studentName, const int resourceID, const string date, vector<campusResource>& resources){
   
// will check resource id exist or not
    bool resourceFound = false;

    //for loop search through resource
    for(int i = 0; i < resources.size(); i++){
        // it will check resoure ID
       if(resources[i].getID() == resourceID){
        resourceFound = true;
       
       // checking resources
       if(resources[i].available())
    {
        // resource make unavailable
        resources[i].setavailable(false);
    }
    else{
        cout << "This resource is not available" << endl;
        cout << "Student will be added to the list." << endl;

        // adding students 
        waitList.newStudent(studentID, resourceID, studentName, date);
        return;

    }
    break;
       }

    }

    // if not found 
    if(!resourceFound){
        cout << "Resource not found." << endl;
        return;
    }

 // creating reservation id
    int reservationID = nextReservationID;
    // if there is already reservation then,
    nextReservationID++;

    Reservation newReservation(reservationID, studentID, studentName, resourceID, date);
    activeReservation.addReservation(newReservation);

    cout << "Reservation created successfully." << endl;
    cout << "Reservation ID: " << reservationID << endl;
}

// creating cencel reservation function
bool ReservationMain::cancelReservation(int reservationID, vector<campusResource>& resources){
//searching reservation from linked list
    Reservation* found =
        activeReservation.findReservation(reservationID);


    // Check if reservation exists
    if(found == nullptr)
    {
        cout << "We are unable to find your reservation." << endl;
        return false;
    }


    // Copy reservation before removing it
    Reservation cancelled = *found;


    // Find the resource that belongs to the reservation
    for(int i = 0; i < resources.size(); i++)
    {
        if(resources[i].getID() == cancelled.getItemID())
        {
            // Resource becomes available again
            resources[i].setavailable(true);

            break;
        }
    }
    // Store cancelled reservation in cancellation history stack
    cancellationHistory.copyCancel(cancelled);

    // Remove reservation from active reservation linked list
    activeReservation.removeReservation(reservationID);
    cout << "Reservation cancelled successfully." << endl;

    return true;

}

bool ReservationMain::undoCancel(vector<campusResource>& resources){
    // Check if cancellation history has something to restore
    if(cancellationHistory.canUndo())
    {
        // Get most recently cancelled reservation
        Reservation restored =
            cancellationHistory.undoCancel();


        // Find the resource
        for(int i = 0; i < resources.size(); i++)
        {
            if(resources[i].getID() == restored.getItemID())
            {
                // Resource unavailable again
                resources[i].setavailable(false);

                break;
            }
        }
        activeReservation.addReservation(restored);

        cout << "Reservation restored successfully." << endl;

        cout << "Restored Reservation ID: "
             << restored.getResID()
             << endl;


        return true;
    }
    cout << "There is nothing to restore. Try again." << endl;

    return false;
}

void ReservationMain::viewActiveReservations() const{
cout << "\nActive Reservations:" << endl;
    // Table headings
    cout << left
         << setw(18) << "ReservationID"
         << setw(15) << "StudentID"
         << setw(22) << "StudentName"
         << setw(15) << "ResourceID"
         << setw(15) << "Date"
         << endl;

    // Display reservations from linked list
    activeReservation.displayReservations();
    
}
void ReservationMain::searchReservation(int reservationID){
    Reservation* found =
        activeReservation.findReservation(reservationID);
    // Check reservation was found or not
    if(found != nullptr)
    {
        cout << "Reservation found." << endl;

        found->display();

        return;
    }
}
void ReservationMain::viewWaitingList(){
    waitList.displayWaitingList();
}

