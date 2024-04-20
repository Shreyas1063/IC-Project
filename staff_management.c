#include "staff_management.h"
#include <stdio.h>
#include <stdlib.h>

#define STAFF_FILE "staff.txt"

// Function to add a staff member to the log
void add_staff(char* staff_type, char* name, char* mobile_number, int on_holiday) {
    // Log the details of the staff member
    FILE *staff_file;
    staff_file = fopen(STAFF_FILE, "a"); // Open the file in append mode
    
    if (staff_file == NULL) {
        printf("Error opening staff file!\n");
        return;
    }
    
    // Check if the staff member is on holiday
    char holiday_status[20];
    if (on_holiday) {
        strcpy(holiday_status, "On Holiday");
    } else {
        strcpy(holiday_status, "Not on Holiday");
    }
    
    fprintf(staff_file, "Type: %s, Name: %s, Mobile Number: %s, Status: %s\n", staff_type, name, mobile_number, holiday_status);
    fclose(staff_file);
}

// Function to display all staff members in the log
void display_staff() {
    // Display the details of all staff members
    FILE *staff_file;
    staff_file = fopen(STAFF_FILE, "r"); // Open the file in read mode
    
    if (staff_file == NULL) {
        printf("Error opening staff file!\n");
        return;
    }

    printf("Staff Details:\n");
    char line[100];
    while (fgets(line, sizeof(line), staff_file) != NULL) {
        printf("%s", line);
    }

    fclose(staff_file);
}
