<<<<<<< HEAD
#include "cancellationHistory.h"
#include <iostream>
using namespace std;

// Constructor for the cancellation history
CancellationHistory::CancellationHistory(){}

// Stores a cancelled reservation on top of the stack
void CancellationHistory::copyCancel(const Reservation reservation){
    cancelledRes.push(reservation);
}

// Checks whether there is a cancelled reservation that can be restored
bool CancellationHistory::canUndo() const{
    return !cancelledRes.empty();
}

// Removes and returns the most recently cancelled reservation
Reservation CancellationHistory::undoCancel(){
    Reservation recent = cancelledRes.top();
    cancelledRes.pop();
    return recent;
}

// Displays the cancellation history without changing the original stack
void CancellationHistory::displayLog() const{

        // If there are no cancelled reservations, display a message
    if (cancelledRes.empty()){
        cout << "No recent cancellations." << endl;
        return;
    }
    
// Make a copy so displaying the history does not remove items
    stack<Reservation> copy = cancelledRes;
    cout << "Cancellation history:" << endl;

    while (!copy.empty()){
        copy.top().display();
        copy.pop();
    }
=======
#include "cancellationHistory.h"
#include <iostream>
using namespace std;

// Constructor for the cancellation history
CancellationHistory::CancellationHistory(){}

// Stores a cancelled reservation on top of the stack
void CancellationHistory::copyCancel(const Reservation reservation){
    cancelledRes.push(reservation);
}

// Checks whether there is a cancelled reservation that can be restored
bool CancellationHistory::canUndo() const{
    return !cancelledRes.empty();
}

// Removes and returns the most recently cancelled reservation
Reservation CancellationHistory::undoCancel(){
    Reservation recent = cancelledRes.top();
    cancelledRes.pop();
    return recent;
}

// Displays the cancellation history without changing the original stack
void CancellationHistory::displayLog() const{

        // If there are no cancelled reservations, display a message
    if (cancelledRes.empty()){
        cout << "No recent cancellations." << endl;
        return;
    }
    
// Make a copy so displaying the history does not remove items
    stack<Reservation> copy = cancelledRes;
    cout << "Cancellation history:" << endl;

    while (!copy.empty()){
        copy.top().display();
        copy.pop();
    }
>>>>>>> c6303a74d491eda37866b4edfed7ac53c19c4bc9
}