#include<iostream>
#include "waitingList.h"

using namespace std;

// initializing an empty queue
WaitingList::WaitingList(){
    first = nullptr;
    last = nullptr;

}
// here by this function we are adding new students to the back.
void WaitingList::newStudent(int studentID, int resourceID, string studentName, string reservationDate){
// allocating memory for new students.
studentNode* newStudent = new studentNode( studentID, resourceID, studentName, reservationDate);

// calling the ifEmp function here
if (ifEmp()){
    first = newStudent;
    last = newStudent;

}
else{
     // it will access new member through pointer
    last->next = newStudent; 
    // it will update member
    last = newStudent; 

}
cout << "Student has been added successfully." << endl;
}

bool WaitingList::getFirstStudent(int& studentID, int& resourceID, string& studentName, string& reservationDate){
    // Check waiting list is empty or not
    if(ifEmp())
    {
        return false;
    }

    // Get information from first student
    studentID = first->studentID;
    resourceID = first->resourceID;
    studentName = first->studentName;
    reservationDate = first->reservationDate;

    return true;
}

// now we are working on removeStudent function
// fouction that removes the student from the front list.
bool WaitingList::removeStudent(){
    if(ifEmp()){
        cout << "None in the List." << endl;
        return false;
    }
// loacal pointer
    studentNode* temporary = first;

    cout << "This student has been removed from queue." << endl;
    cout << "Student ID: " << temporary->studentID << endl;
    cout << "Student Name: " << temporary->studentName << endl;

    // moving member pointer to next struct

    first = first -> next;

    if (first == nullptr){
        // reset member pointer.
        last = nullptr;
    }

    delete temporary;

    return true;
}

    // moving to display waithing function.
    void WaitingList::displayWaitingList(){
        // this if statement return early if there is no student on queue.
        if(ifEmp()){
            cout << "There is none in waiting list." << endl;
            return;
        }

        cout << " Waiting List: "<< endl;
        // setting pointer at very first element
        studentNode* current = first;

        // looping each students untill reach end.
        while(current!=nullptr){
            cout << "Student ID: " << current->studentID<<endl;
            cout << "Student Name: " << current->studentName << endl;
            cout << "Resource ID: " << current->resourceID << endl;
            cout << "Reservation Date: " << current->reservationDate<<endl;

            // moving to next line.
            current = current->next;

        }

    }
    bool WaitingList::ifEmp(){
        return first == nullptr;

    }

    // function to deallocate memory.
    WaitingList::~WaitingList(){
        // using loop to continously delete
        while(first != nullptr){
            studentNode* temporary = first;
            first= first->next;
            delete temporary;
        }
        // makesure to empty.
        last = nullptr; 
    }



    



