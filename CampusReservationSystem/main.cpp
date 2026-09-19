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

    int choice;
    // creating a vector.
    vector<campusResource> resources;

    // calling the function to initialize resources.
    initializeResources(resources);

    // creating a do while loop to display all meanu fro user choice

    do{
        cout << " Campus Resources Reservation System "<< endl; // header
        cout << endl; 
        cout << "1." << " View all resources " << endl; // options
        cout << "2. " << " View available resources " << endl;
        cout << "3. " << " Create Reservation " << endl;
        cout << "4. " << "Cancel Reservation " << endl;
        cout << "5. " <<  " View Active Reservations " << endl;
        cout << "6. " << " Search for reservation " << endl;
        cout << "7. " << "Enter Resource ID " << endl;
        cout << "8. " << "Sort Resources by ID. " << endl;
        cout << "0. " << " Exit " << endl;

        // prompting user to enter choice.
        cout << " Enter number from 0-6 to make choice: " << endl;
        cin >> choice;

        // using switch case to make a choice for user to select what they need

    switch(choice){
        case 1:
        displayResources(resources);
        break; // break for  stop if user enter 1.

        case 2:
        availability(resources);
        break;

        case 3:
        cout << "this is for create reservstion";
        break;

        case 4:
        cout << "This is for cancel reservstion";
        break;

        case 5:
        cout << " This is for active reservation";
        break;

        case 6:
        cout << " search for reservation";
        break;

        case 7:
        // prompting user to enter resource ID.
        cout << "Enter Resource ID: ";
        int id;
        cin >> id;
        // calling findResource function from resource.cpp
        findResource(resources, id);
        break;

        case 8:
        sortResources(resources);

        cout<< "Sort resources by ID" << endl;
        displayResources(resources);
        break;

        case 0:
        cout << " Thank you for using our system. " << endl;
        break;

        default:
        cout << " Invalid Choice. Please try again." << endl;

    }
    
    }while(choice !=0); // Loop will continue untill user enter 0.

return 0;
}