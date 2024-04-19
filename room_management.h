#ifndef ROOM_MANAGEMENT_H
#define ROOM_MANAGEMENT_H

// Include necessary header files
//#include "main.h"
typedef struct {
    char number[MAX_ROOM_NUMBER_LENGTH];
    int capacity;
    int occupancy;
    char roommates[MAX_ROOM_CAPACITY][MAX_NAME_LENGTH]; // Assuming each roommate name has a maximum length
} Room;

// Function declarations
Room* initializeRoomData(int numRooms);
void assignRoom(Room *rooms, int numRooms, char *studentName);
void displayRooms(Room *rooms, int numRooms);

#endif /* ROOM_MANAGEMENT_H */
