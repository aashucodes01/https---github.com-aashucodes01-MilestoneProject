#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

using namespace std;

class Reservation {
    private:
        int reservationID;
        int studentID;
        string studentName;
        int resourceID;
        string reservationDate;
        string startTime;
        string endTime;

       

    public:
        Reservation();
        Reservation(int resID, int stuID, const string stuName, const int itemID, const string date , const string start, const string end);

        int getResID() const;
        int getStuID() const;
        string getStuName() const;
        int getItemID() const;
        string getDate() const;
        string getStartTime()const;
        string getEndTime() const;

        void display() const;

      
};

#endif