#include <iostream>
#include <vector>
#include <string>

#include "resource.h"

using namespace std;

int main()
{
    vector<Resource> resources;

    // Load resources when program starts
    loadResources(resources);

    int choice;

    do
    {
        cout << "\n==================================" << endl;
        cout << "   Reservation Management System" << endl;
        cout << "==================================" << endl;

        cout << "1. View Resources" << endl;
        cout << "2. Add Resource" << endl;
        cout << "3. Search Resource" << endl;
        cout << "4. Make Reservation" << endl;
        cout << "5. Cancel Reservation" << endl;
        cout << "6. View Waiting List" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                displayResources(resources);
                break;
            }

            case 2:
            {
                addResource(resources);
                break;
            }

            case 3:
            {
                string id;

                cout << "Enter resource ID: ";
                cin >> id;

                int index = findResource(resources, id);

                if (index == -1)
                {
                    cout << "Resource not found." << endl;
                }
                else
                {
                    cout << "\nResource Found" << endl;

                    cout << "ID: "
                         << resources[index].id
                         << endl;

                    cout << "Name: "
                         << resources[index].name
                         << endl;

                    cout << "Type: "
                         << resources[index].type
                         << endl;

                    cout << "Status: "
                         << resources[index].status
                         << endl;
                }

                break;
            }

            case 4:
            {
                // Eric will connect reservation code here
                cout << "Reservation module will be connected here."
                     << endl;

                break;
            }

            case 5:
            {
                // Cancellation module connects here
                cout << "Cancellation module will be connected here."
                     << endl;

                break;
            }

            case 6:
            {
                // Waiting list module connects here
                cout << "Waiting list module will be connected here."
                     << endl;

                break;
            }

            case 7:
            {
                saveResources(resources);

                cout << "Program closed." << endl;

                break;
            }

            default:
            {
                cout << "Invalid choice." << endl;
            }
        }

    } while (choice != 7);

    return 0;
}
