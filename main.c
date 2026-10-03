#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold sensor data
typedef struct {
    int sensor_id;
    float temperature;
    char timestamp[20];
} SensorData;

// Function to log reading to console and file
void log_sensor_data(SensorData *data) {
    // Get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(data->timestamp, sizeof(data->timestamp), "%Y-%m-%d %H:%M:%S", t);

    // Print to Console
    printf("[LOG] Time: %s | Sensor ID: %d | Temp: %.2f °C\n", 
            data->timestamp, data->sensor_id, data->temperature);

    // Append to CSV File
    FILE *file = fopen("sensor_logs.csv", "a");
    if (file != NULL) {
        fprintf(file, "%s,%d,%.2f\n", data->timestamp, data->sensor_id, data->temperature);
        fclose(file);
    } else {
        printf("[ERROR] Could not open log file.\n");
    }
}

int main() {
    printf("===========================================\n");
    printf("  Embedded Sensor Data Logger System (C)\n");
    printf("===========================================\n\n");

    // Simulate 3 sensor readings
    SensorData s1 = {101, 24.5f, ""};
    SensorData s2 = {102, 28.1f, ""};
    SensorData s3 = {103, 21.8f, ""};

    log_sensor_data(&s1);
    log_sensor_data(&s2);
    log_sensor_data(&s3);

    printf("\n[SUCCESS] Data successfully saved to 'sensor_logs.csv'.\n");
    return 0;
}