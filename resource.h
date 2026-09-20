#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

using namespace std;

struct Resource
{
    string id;
    string name;
    string type;
    string status;
};

void displayResources(const vector<Resource>& resources);

void addResource(vector<Resource>& resources);

int findResource(const vector<Resource>& resources,
                 const string& id);

void changeAvailability(vector<Resource>& resources,
                        const string& id,
                        bool available);

void loadResources(vector<Resource>& resources);

void saveResources(const vector<Resource>& resources);

#endif
