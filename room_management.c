#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"
#include "room_management.h"

// Define structure for a room
typedef struct {
    char roomNumber[MAX_ROOM_NUMBER_LENGTH];
    int bedCount;
    int fanCount;
    int chairCount;
    int tableCount;
    int almirahCount;
    int bulbCount;
} Room;

// Function to initialize room data
Room* initializeRoomData(int numRooms) {
    Room *rooms = (Room*)malloc(numRooms * sizeof(Room));
    if (rooms == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize room data
    for (int i = 0; i < numRooms; i++) {
        snprintf(rooms[i].roomNumber, MAX_ROOM_NUMBER_LENGTH, "W%d", i + 101);
        rooms[i].bedCount = 0;
        rooms[i].fanCount = 0;
        rooms[i].chairCount = 0;
        rooms[i].tableCount = 0;
        rooms[i].almirahCount = 0;
        rooms[i].bulbCount = 0;
    }

    // Fetch student data and update room occupancy
int numStudents;
Student *students = getAllStudents(&numStudents);
for (int i = 0; i < numRooms; i++) {
    for (int j = 0; j < numStudents; j++) {
        if (strcmp(students[j].room, rooms[i].roomNumber) == 0) {
            rooms[i].bedCount = 1;
            rooms[i].fanCount = 1;
            rooms[i].chairCount = 1;
            rooms[i].tableCount = 1;
            rooms[i].almirahCount = 1;
            rooms[i].bulbCount = 1;
            break;
        }
    }
}

free(students); // Free memory allocated for student data


    return rooms;
}

// Function to display room details
void displayRoomDetails(Room *rooms, int numRooms) {
    printf("Room Number\tBed\tFan\tChair\tTable\tAlmirah\tBulb\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numRooms; i++) {
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\t%d\n", rooms[i].roomNumber, rooms[i].bedCount, rooms[i].fanCount, rooms[i].chairCount, rooms[i].tableCount, rooms[i].almirahCount, rooms[i].bulbCount);
    }
}
