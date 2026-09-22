<<<<<<< HEAD
#ifndef WAITING_LIST_H
#define WAITING_LIST_H
#include <string>
using namespace std;

class WaitingList
{
    private:
// Structure to define each individual student
struct studentNode{
int studentID; // identification number for studnts which is unique.
string studentName; // stores student name.
int resourceID; // stores resource id.
string reservationDate; // stores requested date for reservation.

studentNode*next; // this is a pointer for next student node.

// creating a constructor to initialize a node.
studentNode(int id, int resource, string name, string date){
    studentID = id;
    resourceID = resource;
    studentName = name;
    reservationDate = date;
    next = nullptr;  // this is a new node with null value.

}
};
studentNode* first; //this pointer for first student in line
studentNode* last; // this pointer for last student in line.

public:

// initializing WaitingList() 
WaitingList();

// we are creating a function named newStudent which add new student to the end.
void newStudent(int studentID, int resourceID, string studentName, string reservationDate);

// function for get first student
bool getFirstStudent( int& studentID, int& resourceID, string& studentName, string& reservationDate);
// this function will remove students at the front of the list.
bool removeStudent();

// this function will display all student who are in waiting list.
void displayWaitingList();

// this function returns true when list has no nodes.
bool ifEmp();

// this function will make space by removing nodes.


~WaitingList();




    
};

#endif

=======
#ifndef WAITING_LIST_H
#define WAITING_LIST_H
#include <string>
using namespace std;

class WaitingList
{
    private:
// Structure to define each individual student
struct studentNode{
int studentID; // identification number for studnts which is unique.
string studentName; // stores student name.
int resourceID; // stores resource id.
string reservationDate; // stores requested date for reservation.

studentNode*next; // this is a pointer for next student node.

// creating a constructor to initialize a node.
studentNode(int id, int resource, string name, string date){
    studentID = id;
    resourceID = resource;
    studentName = name;
    reservationDate = date;
    next = nullptr;  // this is a new node with null value.

}
};
studentNode* first; //this pointer for first student in line
studentNode* last; // this pointer for last student in line.

public:

// initializing WaitingList() 
WaitingList();

// we are creating a function named newStudent which add new student to the end.
void newStudent(int studentID, int resourceID, string studentName, string reservationDate);

// this function will remove students at the front of the list.
bool removeStudent();

// this function will display all student who are in waiting list.
void displayWaitingList();

// this function returns true when list has no nodes.
bool ifEmp();

// this function will make space by removing nodes.

~WaitingList();




    
};

#endif

>>>>>>> c6303a74d491eda37866b4edfed7ac53c19c4bc9
