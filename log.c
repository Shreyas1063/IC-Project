#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    
// Function to get current date and time
void getCurrentDateTime(char *dateTime) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(dateTime, 20, "%Y-%m-%d %H:%M:%S", tm);
}

// Function to write log to file
void writeLog(const char *message) {
    FILE *file = fopen("admin_log.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening log file!");
        return;
    }
    char dateTime[20];
    getCurrentDateTime(dateTime);
    fprintf(file, "[%s] %s\n", dateTime, message);
    fclose(file);
}
