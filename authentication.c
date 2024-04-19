#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.h" // Include header file for function declarations

// Define maximum lengths for strings
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define USERS_FILE "users.txt"
#define HASH_SEED 31

// Hashing function
unsigned long hash(char *str) {
    unsigned long hash = 0;
    int c;

    while ((c = *str++)) {
        hash = hash * HASH_SEED + c;
    }

    return hash;
}

// Function to register a new user
void registerUser() {
    FILE *file = fopen(USERS_FILE, "a");
    if (file == NULL) {
        printf("Error opening users file.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Input username and password
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Hash password
    unsigned long hashedPassword = hash(password);

    // Write user record to file
    fprintf(file, "%s %lu\n", username, hashedPassword);

    fclose(file);

    printf("User registered successfully.\n");
}

// Function to login a user
int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Hash password
    unsigned long hashedPassword = hash(password);

    // Check credentials
    FILE *file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("Error opening users file.\n");
        return 0;
    }

    char fileUsername[MAX_USERNAME_LENGTH];
    unsigned long fileHashedPassword;
    int authenticated = 0;

    while (fscanf(file, "%s %lu\n", fileUsername, &fileHashedPassword) != EOF) {
        if (strcmp(username, fileUsername) == 0 && hashedPassword == fileHashedPassword) {
            authenticated = 1;
            break;
        }
    }

    fclose(file);

    if (authenticated) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Invalid username or password.\n");
        return 0;
    }
}
