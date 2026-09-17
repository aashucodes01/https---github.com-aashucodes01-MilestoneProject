#ifndef RESOURCE_HEADER
#define RESOURCE_HEADER
#include<string>
using namespace std;

class campusResource{
    private:
    string resourceName;
    int resourceID;
    string resourceType;
    bool availability;

    public:
    campusResource();
    campusResource(int id, string name, string type);
    int getID();
    string getName();
    string getType();
    bool available();

    void setavailable(bool status);
    void printResource();


};
#endif


