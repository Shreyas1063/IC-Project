#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room_management.h" // Include header file for function declarations

// Define maximum lengths for strings
#define MAX_ROOM_NUMBER_LENGTH 10
#define MAX_ROOM_CAPACITY 4 // Assuming maximum 4 students per room

// Define structure for a room
typedef struct {
    char number[MAX_ROOM_NUMBER_LENGTH];
    int capacity;
    int occupancy;
    char roommates[MAX_ROOM_CAPACITY][MAX_NAME_LENGTH]; // Assuming each roommate name has a maximum length
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
        snprintf(rooms[i].number, MAX_ROOM_NUMBER_LENGTH, "Room %d", i + 1);
        rooms[i].capacity = MAX_ROOM_CAPACITY;
        rooms[i].occupancy = 0;
        for (int j = 0; j < MAX_ROOM_CAPACITY; j++) {
            strcpy(rooms[i].roommates[j], ""); // Initialize roommates' names to empty strings
        }
    }

    return rooms;
}

// Function to assign a student to a room
void assignRoom(Room *rooms, int numRooms, char *studentName) {
    int roomIndex = -1;

    // Find the first available room with empty slots
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].occupancy < rooms[i].capacity) {
            roomIndex = i;
            break;
        }
    }

    // Assign the student to the room
    if (roomIndex != -1) {
        strcpy(rooms[roomIndex].roommates[rooms[roomIndex].occupancy], studentName);
        rooms[roomIndex].occupancy++;
        printf("%s assigned to %s\n", studentName, rooms[roomIndex].number);
    } else {
        printf("No available rooms.\n");
    }
}

// Function to display room details and roommate names
void displayRooms(Room *rooms, int numRooms) {
    printf("Room\t\tCapacity\tOccupancy\tRoommates\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < numRooms; i++) {
        printf("%s\t%d\t\t%d\t\t", rooms[i].number, rooms[i].capacity, rooms[i].occupancy);
        for (int j = 0; j < rooms[i].occupancy; j++) {
            printf("%s", rooms[i].roommates[j]);
            if (j < rooms[i].occupancy - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}
