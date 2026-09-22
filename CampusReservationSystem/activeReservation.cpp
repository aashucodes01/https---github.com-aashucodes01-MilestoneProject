#include "activeReservation.h"
#include<iostream>
using namespace std;

// constructor for active reservation class
ActiveReservation::ActiveReservation(){
// no reservation when program start at first
    head = nullptr;
}

// function to add new reservation to link list
void ActiveReservation::addReservation(Reservation reservation){
    // creating new memory
    reservationNode* newNode = new reservationNode(reservation);

    // check link list
    if(head == nullptr){
        head = newNode;
        return;
    }
    // start form first
    reservationNode* current = head;
       // Move through the list until we reach the last node
    while(current->next != nullptr)
    {
        // Move current to the next node
        current = current->next;
    }

    // conncect last node to new
    current->next = newNode;
}

// function to remove reservation using reservation ID
// This function removes a reservation using its reservation ID
bool ActiveReservation::removeReservation(int reservationID)
{
    // Check if the linked list is empty
    if(head == nullptr)
    {
        return false;
    }

    // Check if the first node is the reservation we want to remove
    if(head->reservation.getResID() == reservationID)
    {
        // Save the first node temporarily
        reservationNode* temporary = head;

        // Move head to the next node
        head = head->next;

        // Delete the old first node
        delete temporary;

        return true;
    }

    // Start from the first node
    reservationNode* current = head;

    // Search through the linked list
    while(current->next != nullptr)
    {
        // Check the next node's reservation ID
        if(current->next->reservation.getResID() == reservationID)
        {
            // Save the node that we want to remove
            reservationNode* temporary = current->next;
            current->next = temporary->next;
            delete temporary;

            return true;
        }

        // Move to the next node
        current = current->next;
    }
    return false;
}

void ActiveReservation::displayReservations()const{
    if(head == nullptr){
         cout << "There are no active reservations." << endl;
        return;
    }

    reservationNode* current = head;

    // go through every linked list
     while(current != nullptr)
    {
        // Display the reservation stored in this node
        current->reservation.display();

        current = current->next;
    }
    
}
// Destructor..
ActiveReservation::~ActiveReservation(){
   // continue untill linked list empty.
    while(head != nullptr){
        reservationNode* temporary = head;

        // Move head to the next node
        head = head->next;
        delete temporary;
    }
}

// Finds a reservation using reservation ID
Reservation* ActiveReservation::findReservation(int reservationID)
{
    // Start from first node
    reservationNode* current = head;

    // Go through linked list
    while(current != nullptr)
    {
        if(current->reservation.getResID() == reservationID)
        {
            return &(current->reservation);
        }
        current = current->next;
    }
    return nullptr;
}
