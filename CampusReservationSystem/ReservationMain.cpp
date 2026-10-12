#include "ReservationMain.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
// constructor..
ReservationMain::ReservationMain()
{
    // First reservation ID starts at 1
    nextReservationID = 1;
}

// function to create reservation.
void ReservationMain::createReservation(const int studentID, const string studentName, const int resourceID, const string date, const string startTime, const string endTime, vector<campusResource>& resources){
   
// will check resource id exist or not
    bool resourceFound = false;

    //for loop search through resource
    for(int i = 0; i < resources.size(); i++){
        // it will check resoure ID
       if(resources[i].getID() == resourceID){
        resourceFound = true;

        //cout the requests
        requestedResourceIDs.push_back(resourceID);
       
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
        waitList.newStudent(studentID, resourceID, studentName, date, startTime, endTime);
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

    Reservation newReservation(reservationID, studentID, studentName, resourceID, date, startTime, endTime);
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

    // this is for check student is waiting for this resource or not
int waitingStudentID;
string waitingStudentName;
string waitingDate;
string waitingStartTime;
string waitingEndTime;


if(waitList.countWaiting(cancelled.getItemID())>0){
    // remove the first student waiting
    bool foundWaiting = waitList.removeFirst(cancelled.getItemID(), waitingStudentID, waitingStudentName, waitingDate, waitingStartTime, waitingEndTime);
    if (foundWaiting){
        // create a new reservation 
        int newID= nextReservationID;
        nextReservationID++;
        
        Reservation newReservation(newID, waitingStudentID,waitingStudentName,cancelled.getItemID(),waitingDate, waitingStartTime, waitingEndTime);
        // add reservation to active link list
        activeReservation.addReservation(newReservation);

        // make resource unavailable again
        for(int i = 0; i< resources.size(); i++ ){
            if(resources[i].getID()==cancelled.getItemID()){
                resources[i].setavailable(false);
                break;
            }
        }
        cout << "Resource assigned to next student." << endl;
        cout << "New ReservationID: "<< newID << endl;

       
    }
    
}
return true;

}



bool ReservationMain::undoCancel(vector<campusResource>& resources){
    //check the last cancelled reservation
    Reservation restored;

    if (!cancellationHistory.peakCancel(restored)){
       cout << "Nothing to restore." << endl;
        return false;
    }

        // Find the resource
        for(int i = 0; i < resources.size(); i++)
        {
            if(resources[i].getID() == restored.getItemID())
            {
              // this is for if resource already reserve do not restore it
              if(!resources[i].available()){
                cout << "Sorry, It cant undo, Resource is already reserved"<< endl;
                return false;

            }
            // Removing cancellation from stack
            cancellationHistory.undoCancel();
            // Reserve resource again
            resources[i].setavailable(false);

        // Resore the reservation.
        activeReservation.addReservation(restored);

        cout << "Reservation restored successfully." << endl;

        cout << "Restored Reservation ID: "
             << restored.getResID()
             << endl;


        return true;
            }
    }
    cout << "There is nothing to restore. Try again." << endl;

    return false;
}

// LINKED LIST to display all active reservation stored in the linked list.
void ReservationMain::viewActiveReservations() const{
cout << "\nActive Reservations:" << endl;
    // Table headings
    cout << left
         << setw(18) << "ReservationID"
         << setw(15) << "StudentID"
         << setw(22) << "StudentName"
         << setw(15) << "ResourceID"
         << setw(15) << "Date"
         << setw(12) << "Start Time"
         << setw(12) << "End Time" 
         << endl;

    // Display reservations from linked list
    activeReservation.displayReservations();
    
}
// Search the active reservation linked list
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
    else {
        cout << "Reservation not found." << endl;
    }
}
void ReservationMain::viewWaitingList(){
    waitList.displayWaitingList();
}

  // Display resources based on how many times they were requested.
void ReservationMain:: showMostRequestedResources(vector<campusResource>& resources)
{
        vector<int> resourceIDs;
        vector<int> counts;

        // count requests for each resource
        for(campusResource& resource : resources){
            int count =0;
            for(int requestedID : requestedResourceIDs){
            if(requestedID == resource.getID()){
                count++;
                
            }
        }
        resourceIDs.push_back(resource.getID());
        counts.push_back(count);

        }
        // sort the resources
        for(int i = 0; i <(int)counts.size(); i++){
            for(int j = i +1; j<(int)counts.size(); j++){
                if(counts[j] > counts[i]){
                    // swapping
                    int tempCount = counts[i];
                    counts[i] = counts[j];
                    counts[j] = tempCount;

                // Swap the resource IDs
                int tempID = resourceIDs[i];
                resourceIDs[i] = resourceIDs[j];
                resourceIDs[j] = tempID;

                }
            }
        }
        // Display the report 
        cout << endl;
        cout << "Most Requested Resources Report" << endl;
        cout << " Resource ID \t Total Requests" << endl;

        for (int i = 0; i < (int)resourceIDs.size(); i++)
         {
        cout << resourceIDs[i] << "\t\t" << counts[i] << endl;
         }
}

// function for display the waiting list stastics
void ReservationMain:: showWaitingListStatistics(vector<campusResource>& resources){
    int totalWaiting = 0;
    cout << " Waiting List Statistics Report" << endl;

    // checking wach resource
    for(campusResource& resource: resources){
        // count students
        int count = waitList.countWaiting(resource.getID());

        cout << "ResourceID: " << resource.getID()<< endl;
        cout << "Resource Name: " << resource.getName()<< endl;
        cout << "Waiting Students: " << count << endl;
        cout << endl;

        // add total number of wait list
        totalWaiting += count;

    }
    cout << endl; 
    cout << "Total Students Waiting: " << totalWaiting << endl;

}

