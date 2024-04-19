#ifndef ROOM_MANAGEMENT_H
#define ROOM_MANAGEMENT_H

// Include necessary header files
//#include "main.h"


// Function declarations
Room* initializeRoomData(int numRooms);
void assignRoom(Room *rooms, int numRooms, char *studentName);
void displayRooms(Room *rooms, int numRooms);

#endif /* ROOM_MANAGEMENT_H */
