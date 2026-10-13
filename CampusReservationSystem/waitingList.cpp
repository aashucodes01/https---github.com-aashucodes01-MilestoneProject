#include<iostream>
#include "waitingList.h"

using namespace std;

// initializing an empty queue
WaitingList::WaitingList(){
    first = nullptr;
    last = nullptr;

}
// here by this function we are adding new students to the back.
void WaitingList::newStudent(int studentID, int resourceID, string studentName, string reservationDate, string startTime, string endTime){
// allocating memory for new students.
studentNode* newStudent = new studentNode( studentID, resourceID, studentName, reservationDate, startTime, endTime);

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

bool WaitingList::getFirstStudent(int& studentID, int& resourceID, string& studentName, string& reservationDate, string& startTime, string& endTime){
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
    startTime = first->startTime;
    endTime = first->endTime;

    return true;
}

// this function counts how many student  are waiting 
int WaitingList::countWaiting(int resourceID){
int count =0;
studentNode* current = first;

while (current != nullptr){
    if(current->resourceID==resourceID){
        count++;
    }
    current = current->next;

}
return count;

}

// this function is for find the first student for waiting 
bool WaitingList::removeFirst(int resourceID, int&studentID, string& studentName, string&reservationDate, string& startTime, string& endTime){
    studentNode* current = first;
    studentNode* previous = nullptr;

    while(current!=nullptr){
        if(current -> resourceID==resourceID){

        studentID = current->studentID;
        studentName = current->studentName;
        reservationDate = current->reservationDate;
        startTime = current->startTime;
        endTime = current->endTime;

            // saves student first in the queue, move first forward
            if(previous == nullptr){
                first = current->next;
            }
            else{
                previous->next = current ->next;
            }
 // remove last studdent nnd update last
            if(current==last){
                last = previous;

            }
// delete the student from queue
            delete current;
            return true;
        }
        previous = current;
        current =current->next;
    }
    return false; 
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
            cout << "Start Time: " << current->startTime << endl;
            cout << "End Time: " << current->endTime << endl;

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



    



