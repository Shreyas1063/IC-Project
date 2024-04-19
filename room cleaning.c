#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "man_management.h" // Include header file for function declarations
#include "student_management.h" // Include header file for student details

#define COMPLAINTS_FILE "cleaning_complaints.txt"

void order_room_cleaning(char* room_number, Student* students, int numStudents) {
    // Find student details by room number
    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].room, room_number) == 0) {
            // Student found, order room cleaning
            printf("Room cleaning ordered for room %s, occupied by %s\n", room_number, students[i].name);
            
            // Log the cleaning order in a file
            FILE *log_file;
            log_file = fopen(COMPLAINTS_FILE, "a"); // Open the file in append mode
            
            if (log_file == NULL) {
                printf("Error opening log file!\n");
                return;
            }
            
            fprintf(log_file, "Cleaning ordered for room %s, occupied by %s\n", room_number, students[i].name);
            fclose(log_file);

            return; // Exit function after ordering room cleaning
        }
    }

    // If room number not found in the database
    printf("Room number %s not found in the database.\n", room_number);
}

