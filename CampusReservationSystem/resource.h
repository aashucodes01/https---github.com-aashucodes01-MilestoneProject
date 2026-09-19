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

// it will find resources using its ID
void findResource(vector<campusResource>& resources, int id);

// it will shorts resources by Resource ID
void sortResources(vector<campusResource>& resources);

// It will merge sorted parts.
void mergeResources(vector<campusResource>& resources, int left, int middle, int right);

// here we perform merge sort
void mergeSort(vector<campusResource>& resources, int left, int right);

#endif


