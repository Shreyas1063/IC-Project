#ifndef ROOM_MANAGEMENT_H
#define ROOM_MANAGEMENT_H

// Include necessary header files
//#include "main.h"
typedef struct {
    char roomNumber[MAX_ROOM_NUMBER_LENGTH];
    int bedCount;
    int fanCount;
    int chairCount;
    int tableCount;
    int almirahCount;
    int bulbCount;
} Room;

// Function declarations
Room* initializeRoomData(int numRooms);
void assignRoom(Room *rooms, int numRooms, char *studentName);
void displayRooms(Room *rooms, int numRooms);

#endif /* ROOM_MANAGEMENT_H */
