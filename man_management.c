#include "man_management.h"
#include <stdio.h>

void log_entry_exit(char* student_name, char* room_number, char* action) {
    // Log the entry or exit of a student into or from their room
    FILE *log_file;
    log_file = fopen("student_logs.txt", "a"); // Open the file in append mode
    
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    
    fprintf(log_file, "%s %s room %s\n", student_name, action, room_number);
    fclose(log_file);
}

void enter_room(char* student_name, char* room_number) {
    // Record the entry of a student into their room
    printf("%s entered room %s\n", student_name, room_number);
    log_entry_exit(student_name, room_number, "entered");
}

void leave_room(char* student_name, char* room_number) {
    // Record the exit of a student from their room
    printf("%s left room %s\n", student_name, room_number);
    log_entry_exit(student_name, room_number, "left");
}
