# CPU-Intro Homework Answers

## Question 1
100%. Since all instructions are CPU instructions.

## Question 2
Uses 11 units of time in total.

## Question 3
Uses 7 units of time. While PID 0 is blocked for 5 units, PID 1 can run.

## Question 4
Uses 11 units of time as the ready process cannot be run while the other process is blocked.

## Question 5
Uses 7 units of time. See Question 3.

## Question 6
No, because when PID 0 is blocked for I/O, the CPU is idle when it could've been used to run the other processes.

## Question 7
The difference is that the CPU is never idle. By running a process that just completed an I/O, we can minimize the chance of CPU idle if the process has more I/O calls in the future to space out the use of CPU by other processes.

## Question 8
for "-s -3 -l 3:50,3:50"
IO_RUN_IMMEDIATE: 17 units
IO_RUN_LATER: 18 units
SWITCH_ON_IO: 18 units
SWITCH_ON_END: 24 units

So it seems like IO_RUN_IMMEDIATE reduces CPU idle slightly.
