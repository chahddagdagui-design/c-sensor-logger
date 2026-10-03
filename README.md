# c-sensor-logger
Modular C program simulating embedded sensor data logging
# Embedded Sensor Data Logger (C)

A C project simulating a low-level sensor data logging system using dynamic structures and file persistence.

## Features
- **Data Persistence:** Logged readings are exported directly to a `sensor_logs.csv` file.
- **Embedded Concepts:** Demonstrates use of C `structs`, pointers, and `<time.h>` header.

## How to Compile & Run
```bash
gcc main.c -o sensor_logger
./sensor_logger