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
           cout << endl;
           cout << endl;
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
            cout << endl;
            if(resource.available()){ // if available.
                cout << "Yes, This is available" << endl;
            }
          
            else{
                cout << "We are sorry, This is not available" << endl;
            }
            cout << endl;
            cout << endl;

        }

    }

    // creating a findresources function that find resources using its ID
    // here we used linear search method.
    void findResource(vector<campusResource>& resources, int id){

        bool gotIt = false; // this bool value initialize as false because it will track if a match is made or not.
        // using for loop for check each campusResource object in resources vector
        for (campusResource& resource : resources){
            if (resource.getID() == id){ // checking resource ID matches the request or not
               // if yes then...
                cout<< "Resource Found." << endl;
                cout << " Resource ID: " << resource.getID()<< endl;
                cout << "Resource Name: " << resource.getName() << endl;
                cout << "Resource Type: "<< resource.getType()<< endl;

                // now lets check matched resource is currently available or not.
                if (resource.available()){
                    // if yes print this
                     cout << "Yes, This resources is available to use." << endl;
                     cout << endl;
                }
                
                // if not print this
                else{
                    cout << " Sorry, This resource is not available at the moment." << endl;

                }
                // setting a gotIt flag to know program we already got matching resource.
                gotIt = true;

                break; // this is for stop for loop here.

            }
        }

        // if resource not found in list then. print this.
        if(!gotIt){
            cout << "Resource " << id << " not found. Try other resources. "<< endl;
        }
    }
    // creating a sortResources function which sorts all resources by resource id.
    void sortResources(vector<campusResource>& resources)
    {
        // this if statement only sort vectors when vector has more than 1 element
        if(resources.size()>1){
            //calling recursive merge sort
            mergeSort(resources, 0, resources.size()-1);
        }
    }

    // creating a mergeSort function.
    void mergeSort(vector<campusResource>& resources, int left, int right){
       // continue spliting
        if (left < right){
            //first it find mid point
            int middle = (left+right)/2;
            // sort left half then right half and merge sorts all together
            mergeSort(resources, left, middle);
            mergeSort(resources, middle +1, right);
            mergeResources(resources, left, middle, right);
        }

    }

    // creating a mergeResources to combile two sorted sections
    void mergeResources(vector<campusResource>&resources, int left, int middle, int right)
    {
        // temporary vector
        vector <campusResource> temporary;
        int l = left; // starting index for left
        int m = middle + 1; // starting index from right

        // compare elements from both halfs
        while(l <= middle && m <= right){
            if(resources[l].getID() <= resources[m].getID()){
                temporary.push_back(resources[l]);
                l++;
            }
            else{
                temporary.push_back(resources[m]);
                m++;
            }

        } // while ends
        // to copy remaining elements from the left subarray.
        while(l<= middle){
            temporary.push_back(resources[l]);
            l++;
        } // while ends

        // to copy remaining from right
        while(m <= right)
        {
            temporary.push_back(resources[m]);
            m++;
        } // while ends

        // to copy mrged elements back into the original vector
        //using for loop
        for(size_t k = 0; k < temporary.size(); k++)
        {
            resources[ left+k] = temporary[k];

        }

    } 
