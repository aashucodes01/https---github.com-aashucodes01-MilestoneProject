#include <iostream>
#include "resource.h"
#include <vector>
#include <fstream>

using namespace std;

campusResource::campusResource()
{
    resourceID = 0;
    resourceName = "";
    resourceType = "";
    availability = false;
}

campusResource::campusResource(int id, string name, string type)
{
    resourceID = id;
    resourceName = name;
    resourceType = type;
    availability = true;

}

int campusResource::getID()
{
    return resourceID;
}

string campusResource::getName()
{
    return resourceName;
}

string campusResource::getType()
{
    return resourceType;
}

bool campusResource::available()
{
    return availability;
}

void campusResource::setavailable(bool status)
{
    availability = status;
}

 void initializeResources(vector<campusResource>& resources) // we are creating a function here which doesnt return value.
  {
    ifstream inputFile("resources.txt"); // it opens the resource.txt file in our project
 
    // checking weather the file is opened or not if not it shows the error.
    if(!inputFile){ 
        cout << "Error: Couldn't open resources." << endl;
    }
    // declearing variables to hold data.
    int id;
    string name;
    string type;

    // it will keep reading the file is vaild ID name and type
    while (inputFile >> id >> name >> type){
        // creating campus resource object and adding new resource object to vector
        campusResource(id, name, type);
        resources.push_back(campusResource(id, name, type));
        
    }
    // closing inputfile
    inputFile.close();

}

void displayResources(vector<campusResource>& resources) // we are creating a resources function here which doesnt return value.
    {
        // Printing heading
        cout << "\n Campus Resources" << endl;

        //we are going through each resource and displaying the resources.
        for(campusResource& resource : resources){
            cout << "Resource ID: " << resource.getID() << endl;
            cout << "Resource Name: " << resource.getName() << endl;
            cout << "Resource Type: " << resource.getType() << endl;
            if(resource.available()){ // if available.
                cout << "Yes, This is available" << endl;
            }
            else{
                cout << "We are sorry, This is not available" << endl;
            }
        }

    }

    // creating a Availability function that display the availabilty of every resources
    void availability(vector<campusResource>& resources)
    {
        // Printing heading
        cout << "\n Campus Resources Availability" << endl;

        //we are going through each resource and displaying the resources availibility.
        for(campusResource& resource : resources){
            cout << "Resource ID: " << resource.getID() << endl;
            cout << "Resource Name: " << resource.getName() << endl;
            cout << "Resource Type: " << resource.getType() << endl;
            if(resource.available()){ // if available.
                cout << "Yes, This is available" << endl;
            }
            else{
                cout << "We are sorry, This is not available" << endl;
            }
        }

    }
