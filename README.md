# Elevator Simulation Project

## Overview

This project is a simulation of an elevator system implemented in C++. It is designed to handle multiple floor requests dynamically, processing requests for upward and downward movement based on the elevator's current state and user input. The system automatically manages elevator direction and prioritizes requests to optimize efficiency.

## Features

- **Dynamic Request Handling**: Processes multiple floor requests in both upward and downward directions.
- **Optimized Request Queueing**: Efficiently manages floor requests using sorting algorithms and separate queues for upward and downward requests.
- **Real-Time Processing**: The elevator responds to new floor requests during its operation, adjusting its direction dynamically.
- **Idle Mode**: When no requests are pending, the elevator remains in an idle state awaiting new requests.
- **Object-Oriented Design**: The simulation is built using an object-oriented approach with classes for `Elevator` and `Building` to encapsulate elevator logic.

## How It Works

1. **Request Input**: Users can input a floor number to request the elevator. Requests are added to the appropriate queue (up or down) depending on the current position of the elevator.
2. **Movement Simulation**: The elevator moves floor by floor, responding to the user's requests. It processes all upward requests before switching to handle downward requests, optimizing movement.
3. **Console Output**: The simulation provides detailed logs of the elevator's movement, current floor, and direction after each action.

## Tech Stack

- **Languages**: C++
- **Data Structures**: Vectors, Queues
- **Algorithms**: Sorting (ascending and descending order)
- **Object-Oriented Programming**: Class design and encapsulation
- **Development Tools**: Visual Studio IDE

## How to Run the Simulation

1. **Clone the Repository**:  
   ```bash
   git clone https://github.com/bhattacharyasaikat/Elevator-Simulation-System

