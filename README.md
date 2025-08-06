# CPU Scheduling Project

## Overview

This project is a simulation of four different CPU scheduling algorithms implemented in C++ as part of the Operating System lab in the 3rd Year, 2nd Semester, Department of CSE, Sheikh Hasina University. The program reads input data from a file, processes the scheduling algorithms, and outputs the results to another file.

### Algorithms Implemented:
1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Priority Scheduling**
4. **Round Robin (RR)**

Each scheduling algorithm computes essential metrics, including Waiting Time, Turnaround Time, and Completion Time for the processes and displays the results both on the console and in an output file.

## Project Structure


├── README.md # Project documentation
├── scheduling_file.txt # File where output is stored
└── main.cpp # Main C++ file containing the scheduling logic

## Requirements

- C++ compiler (GCC/Clang or others)
- Basic understanding of CPU Scheduling Algorithms

## Features

- **File Input/Output**: Users provide process data (arrival time, burst time, priority) through an input file. The program then processes the data and stores results in an output file.
- **Interactive Menu**: Allows users to select the desired scheduling algorithm via a menu-driven interface.
- **Computation of Key Metrics**: Calculates key metrics such as completion time, waiting time, and turnaround time for each process.

## Usage

1. **Prepare the Input File**:
   The input file should contain process data in the following format:
ProcessID ArrivalTime BurstTime Priority
1 0 5 2
2 1 4 1
3 2 3 3

2. **Compile the Code**:
Use a C++ compiler to compile the code:
```bash
g++ main.cpp -o cpu_scheduler
3. **Run the Program**:
After compiling, run the executable:
./cpu_scheduler
4. **Select a Scheduling Algorithm**:
The program will display a menu with the following options:
1. FCFS Scheduling
2. SJF Scheduling
3. Priority Scheduling
4. RR Scheduling
5. Exit
5. **Check the Output File**:
The results of the selected scheduling algorithm will be written to scheduling_file.txt in the following format:
ProcessID | ArrivalTime | BurstTime | CompletionTime | WaitingTime | TurnaroundTime
##Example Input (input.txt):
ProcessID ArrivalTime BurstTime Priority
1         0           5         2
2         1           4         1
3         2           3         3

##Example Output (scheduling_file.txt):
FCFS Scheduling..........
Process  Arrival_time  Burst_time  Completion_time  Waiting_time  Turnaround_time
1         0           5            5               0             5
2         1           4            9               4             8
3         2           3            12              7             10

Average Waiting Time:  3.66667
Average Turnaround Time: 7.66667


