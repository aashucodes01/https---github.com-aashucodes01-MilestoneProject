#include "cancellationHistory.h"
#include <iostream>
using namespace std;

// Constructor for CancellationHistory.
// Creates an empty cancellation history stack.
CancellationHistory::CancellationHistory(){}

// Stores a cancelled reservation in the stack.
// The most recently cancelled reservation is placed on top.
void CancellationHistory::copyCancel(const Reservation reservation){
    cancelledRes.push(reservation);
}

// Checks whether there is at least one cancelled reservation available to undo.
// Returns true when the stack is not empty and false when it is empty.
bool CancellationHistory::canUndo() const{
    return !cancelledRes.empty();
}

// Restores the most recently cancelled reservation.
// Because the stack uses LIFO order, the last cancelled reservation is returned first.
Reservation CancellationHistory::undoCancel(){
    Reservation recent = cancelledRes.top();
    cancelledRes.pop();
    return recent;
}

// Displays the cancellation history from most recent to oldest.
// A copy of the stack is used so the original cancellation history is not changed.
void CancellationHistory::displayLog() const{
    // If there are no cancelled reservations, display a message and stop.
    if (cancelledRes.empty()){
        cout << "No recent cancellations." << endl;
        return;
    }

    // Copy the stack so we can display its contents without removing
    // reservations from the original cancellation history.
    stack<Reservation> copy = cancelledRes;
    cout << "Cancellation history:" << endl;

    // Display each cancelled reservation from newest to oldest.
    while (!copy.empty()){
        copy.top().display();
        copy.pop();
    }
}
