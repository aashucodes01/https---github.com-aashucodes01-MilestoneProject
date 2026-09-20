#include "queue.h"
#include <iostream>
#include <iomanip>

waitList::waitList(){}

void waitList::addRequest(const queueRequest request){
    queues[request.resourceID].push(request);
}

bool waitList::isWaiting(const string resourceID) const{
    auto findID = queues.find(resourceID);
    if (findID == queues.end()){
        return false;
    }
    return !findID->second.empty();
}

queueRequest waitList::next(const string resourceID){
    queueRequest front = queues[resourceID].front();
    queues[resourceID].pop();
    return front;

}

void waitList::display() const{
    bool stuWaiting = false;

    cout << left << setw(10) << setw(10) << "Resource"<< setw(10) << "StudentID" << setw(20) << "StudentName" << setw(12) << "Requested" << endl;
    //cout << string(52, '-') << endl;

    for (const auto entry : queues){
        queue<queueRequest> copy = entry.second;

        while(!copy.empty()){
            const queueRequest r = copy.front();
            cout << left << setw(10) << r.resourceID << setw(10) << r.studentID << setw(20) << r.studentName << setw(12) << r.date << endl;
            copy.pop();
            stuWaiting = true;
        }
    }

    if(!stuWaiting){
        cout << "Waiting list empty." << endl;
    }
}