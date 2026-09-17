#include <iostream> // program header allows to us cout cin 
#include "resource.h" // It includes the campusResource class 
#include <vector>
#include <fstream>

using namespace std;

   /*
   we are creating a vector here which stores each resources inside the vector.
   here vector contains campusResource object.
   */
 
int main(){

    // creating a vector.
    vector<campusResource> resources;

    // calling the function to initialize resources.
    initializeResources(resources);

    displayResources(resources); // calling the function to display all the resources.

    // calling the function to display is it available or not.
    availability(resources);

    //

}