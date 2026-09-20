#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <map>
#include <string>
using namespace std;

//User request for a resource(ID)

struct queueRequest{
    int studentID;
    string studentName;
    string resourceID;
    string date;
};


//Queue is in a first in first out (FIFO)
class waitList{
    private:
        map<string, queue<queueRequest>> queues;

    public:
        waitList();

        //add student to the back of the queue
        void addRequest(const queueRequest request);

        //True/false if resource is avaliable
        bool isWaiting(const string resourceID) const;

        //Removes the oldest queue and returns the resource to avaliable
        queueRequest next(const string resourceID);

        void display() const;
};

#endif