#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 15
#define MAX_ROOM_LENGTH 10
#define MAX_ROLL_LENGTH 15

// Define structure for student record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char contact[MAX_CONTACT_LENGTH];
    char room[MAX_ROOM_LENGTH];
    char roll[MAX_ROLL_LENGTH];
} Student;

// Function declarations
void addStudent();
void displayStudents();
Student* getAllStudents();

#endif /* STUDENT_MANAGEMENT_H */
