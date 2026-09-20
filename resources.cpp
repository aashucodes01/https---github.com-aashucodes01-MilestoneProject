#include "resource.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;


// Displays all resources
void displayResources(const vector<Resource>& resources)
{
    if (resources.empty())
    {
        cout << "No resources available." << endl;
        return;
    }

    cout << "\n========== Resource List ==========" << endl;

    for (int i = 0; i < resources.size(); i++)
    {
        cout << "ID: " << resources[i].id << endl;
        cout << "Name: " << resources[i].name << endl;
        cout << "Type: " << resources[i].type << endl;
        cout << "Status: " << resources[i].status << endl;

        cout << "-----------------------------------" << endl;
    }
}


// Adds a new resource
void addResource(vector<Resource>& resources)
{
    Resource newResource;

    cout << "\nEnter resource ID (example R121): ";
    cin >> newResource.id;

    // Check for duplicate ID
    if (findResource(resources, newResource.id) != -1)
    {
        cout << "Resource ID already exists." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter resource name: ";
    getline(cin, newResource.name);

    cout << "Enter resource type: ";
    getline(cin, newResource.type);

    // New resource starts as available
    newResource.status = "Available";

    resources.push_back(newResource);

    saveResources(resources);

    cout << "Resource added successfully." << endl;
}


// Searches for resource by ID
int findResource(const vector<Resource>& resources,
                 const string& id)
{
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


// Changes resource status
void changeAvailability(vector<Resource>& resources,
                        const string& id,
                        bool available)
{
    int index = findResource(resources, id);

    if (index == -1)
    {
        cout << "Resource not found." << endl;
        return;
    }

    if (available)
    {
        resources[index].status = "Available";
    }
    else
    {
        resources[index].status = "Unavailable";
    }

    saveResources(resources);
}


// Loads resources from resources.txt
void loadResources(vector<Resource>& resources)
{
    ifstream file("resources.txt");

    if (!file)
    {
        cout << "Could not open resources.txt." << endl;
        return;
    }

    resources.clear();

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        Resource temp;

        getline(ss, temp.id, '|');
        getline(ss, temp.name, '|');
        getline(ss, temp.type, '|');
        getline(ss, temp.status);

        if (!temp.id.empty() &&
            !temp.name.empty() &&
            !temp.type.empty() &&
            !temp.status.empty())
        {
            resources.push_back(temp);
        }
    }

    file.close();
}


// Saves resources to resources.txt
void saveResources(const vector<Resource>& resources)
{
    ofstream file("resources.txt");

    if (!file)
    {
        cout << "Could not save resources.txt." << endl;
        return;
    }

    for (const Resource& resource : resources)
    {
        file << resource.id << "|"
             << resource.name << "|"
             << resource.type << "|"
             << resource.status << endl;
    }

    file.close();
}
