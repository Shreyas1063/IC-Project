#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"
#include "room_management.h"
#include "authentication.h"
#include "complaint.h"
#include "admincomplaint.h"
#include "visitor.h"
#include "staff_management.h" // Include staff management header file

int main() {
    int choice;
    int login_choice;
    int loggedIn = 0;
    do {
        printf("Enter choice for login:\n");
        printf("1. Admin\n2. Student\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &login_choice);
        getchar(); // Consume newline character left in the buffer

        switch (login_choice) {
            case 1:
                if(adminUser()){
                    loggedIn = 1;
                }
                break;
            case 2:
                if(loginUser()){
                    loggedIn = 1;
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (!loggedIn);
    
    if(login_choice == 1){
        // Load room data
        int numRooms = 10; // Example: 10 rooms
        Room *rooms = initializeRoomData(numRooms);
        
        do {
            printf("\nHostel Management System\n");
            printf("1. Add Student\n");
            printf("2. Display Students\n");
            printf("3. Register admin\n");
            printf("4. Register student\n");
            printf("5. Load complaints\n");
            printf("6. Input complaints\n");
            printf("7. Update complaints\n");
            printf("8. Load visitors\n");
            printf("9. Add visitor\n");
            printf("10. Display Room Details\n");
            printf("11. Add Staff\n"); // New option
            printf("12. Display Staff\n"); // New option
            printf("13. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); // Consume newline character left in the buffer

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayStudents();
                    break;
                case 3:
                    registerAdminUser();
                    break;
                case 4:
                    registerUser();
                    break;
                case 5:
                    loadComplaints();
                    break;
                case 6:
                    inputComplaintDetails();
                    break;
                case 7:
                    inputComplaintUpdate();
                    break;
                case 8:
                    loadVisitors();
                    break;
                case 9:
                    addVisitor();
                    break;
                case 10:
                    displayRoomDetails(rooms, numRooms);
                    break;
                case 11:
                    add_staff_case(); // Call to add staff function
                    break;
                case 12:
                    display_staff(); // Call to display staff function
                    break;
                case 13:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 13);

        // Free allocated memory for rooms
        free(rooms);
    }
    else if(login_choice == 2){

    }
    else{}
    return 0;
}
