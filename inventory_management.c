#include "inventory_management.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "student_management.h" // Include header file for student details

#define INVENTORY_FILE "inventory.txt"
#define LOG_FILE "inventory_logs.txt"
#define MAX_NAME_LENGTH 50

// Function to record inventory issuance in the log
void log_inventory_issue(char* student_name, char* item) {
    // Get current date and time
    time_t raw_time;
    struct tm *timeinfo;
    char timestamp[50];

    time(&raw_time);
    timeinfo = localtime(&raw_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Log the issuance of inventory item with date and time
    FILE *log_file;
    log_file = fopen(LOG_FILE, "a"); // Open the file in append mode
    
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    
    fprintf(log_file, "%s issued %s at %s\n", student_name, item, timestamp);
    fclose(log_file);
}

// Function to issue an item from the inventory
void issue_inventory_item(char* student_name, char* item) {
    // Open the inventory file
    FILE *inventory_file;
    inventory_file = fopen(INVENTORY_FILE, "r+"); // Open the file in read/write mode
    
    if (inventory_file == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    // Check if the item is available in the inventory
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), inventory_file) != NULL) {
        if (strstr(line, item) != NULL) {
            found = 1;
            // Move file pointer back to overwrite the line
            fseek(inventory_file, -strlen(line), SEEK_CUR);
            // Write "Not Available" instead of the item
            fprintf(inventory_file, "Not Available\n");
            // Log the issuance of the item
            log_inventory_issue(student_name, item);
            printf("Item '%s' issued to %s\n", item, student_name);
            break;
        }
    }

    if (!found) {
        printf("Item '%s' not found in inventory\n", item);
    }

    fclose(inventory_file);
}

// Function to display the available items in the inventory
void display_inventory() {
    FILE *inventory_file;
    inventory_file = fopen(INVENTORY_FILE, "r"); // Open the file in read mode
    
    if (inventory_file == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    printf("Available Inventory Items:\n");
    char line[100];
    while (fgets(line, sizeof(line), inventory_file) != NULL) {
        if (strstr(line, "Available") != NULL) {
            printf("%s", line);
        }
    }

    fclose(inventory_file);
}
