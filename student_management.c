#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h" // Include header file for function declarations

// Define maximum lengths for strings
/*#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 15
#define MAX_ROOM_LENGTH 10
#define MAX_ROLL_LENGTH 15*/
#define DATABASE_FILE "students.txt"

// Function to add a new student to the database
void addStudent() {
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    Student newStudent;

    // Input student details
    printf("Enter name: ");
    fgets(newStudent.name, MAX_NAME_LENGTH, stdin);
    strtok(newStudent.name, "\n"); // Remove newline character

    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    getchar(); // Consume newline character left in the buffer

    printf("Enter contact info: ");
    fgets(newStudent.contact, MAX_CONTACT_LENGTH, stdin);
    strtok(newStudent.contact, "\n"); // Remove newline character

    printf("Enter room number: ");
    fgets(newStudent.room, MAX_ROOM_LENGTH, stdin);
    strtok(newStudent.room, "\n"); // Remove newline character

    printf("Enter roll number: ");
    fgets(newStudent.roll, MAX_ROLL_LENGTH, stdin);
    strtok(newStudent.roll, "\n"); // Remove newline character

    // Write student record to file
    fprintf(file, "%s,%d,%s,%s,%s\n", newStudent.name, newStudent.age, newStudent.contact, newStudent.room, newStudent.roll);

    fclose(file);
}

// Function to display all students in the database
void displayStudents() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    printf("%-15s\t\tAge\t%-10s\t\tRoom\t\tRoll\n", "Name", "Contact");
    printf("----------------------------------------------------------------------------\n");

    Student currentStudent;
    while (fscanf(file, "%49[^,],%d,%14[^,],%9[^,],%14[^\n]\n", currentStudent.name, &currentStudent.age, currentStudent.contact, currentStudent.room, currentStudent.roll) != EOF) {
        printf("%-15s\t\t%d\t%-10s\t\t%s\t\t%s\n", currentStudent.name, currentStudent.age, currentStudent.contact, currentStudent.room, currentStudent.roll);
    }

    fclose(file);
}

// Function to count the number of lines in a file
int countLines(FILE *file) {
    int count = 0;
    char buffer[1024]; // Assuming maximum line length is 1024 characters

    // Count lines in the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] != '\n' && buffer[0] != '#') { // Exclude empty lines and comments
            count++;
        }
    }

    rewind(file); // Reset file pointer to the beginning

    return count;
}

// Function to fetch all student records
Student* getAllStudents(int *numStudents) {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        return NULL;
    }

    // Determine the number of students in the file
    *numStudents = countLines(file);

    // Allocate memory for student records
    Student *students = (Student*)malloc((*numStudents) * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read student records from file
    int count = 0;
    while (count < *numStudents && fscanf(file, "%49[^,],%d,%14[^,],%9[^,],%14[^\n]\n", students[count].name, &students[count].age, students[count].contact, students[count].room, students[count].roll) != EOF) {
        count++;
    }

    fclose(file);

    return students;
}
