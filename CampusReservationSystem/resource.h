#ifndef RESOURCE_HEADER
#define RESOURCE_HEADER
#include<string>
#include<vector>
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

// Reads resources from resources.txt
void initializeResources(vector<campusResource>& resources);

// Displays all resources
void displayResources(vector<campusResource>& resources);

// Displays availability of all resources
void availability(vector<campusResource>& resources);
#endif


