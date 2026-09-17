#include <iostream>
#include "resource.h"

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

void campusResource::printResource()
{
    cout << "Resource ID: " << resourceID << endl;
    cout << "Resource Name: " << resourceName << endl;
    cout << "Resource Type: " << resourceType << endl;
   if(availability==true){
    cout << "Yes, This is available" << endl;
   }
   else{
    cout << "We are sorry, This is not available" << endl;
   }
}
