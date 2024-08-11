#include "types.h"
#include "user.h"

#define NUM_PROCESSES 5

void testAging(void) {
    printf(1, "Starting aging scheduler test...\n");

    int i, pid;
    int priorities[NUM_PROCESSES] = {0, 5, 10, 15, 20}; // Initial priorities for processes

    // Fork processes with different initial priorities
    for (i = 0; i < NUM_PROCESSES; i++) {
        pid = fork();
        if (pid < 0) {
            printf(2, "Error in fork()\n");
            exit();
        } else if (pid == 0) {
            // In the child process
            setpriority(priorities[i]); // Set initial priority
            printf(1, "Child process %d with initial priority %d started.\n", getpid(), priorities[i]);

            // Simulate some work and observe priority changes
            for (int j = 0; j < 5000000; j++) {
                asm("nop");
            }

            printf(1, "Child process %d with priority %d finished.\n", getpid(), getpriority());
            exit();
        }
    }

    // In the parent process
    for (i = 0; i < NUM_PROCESSES; i++) {
        int ret_pid = wait();
        printf(1, "Parent: Child with PID %d has finished.\n", ret_pid);
    }

    printf(1, "Aging scheduler test completed.\n");
}

int main(int argc, char *argv[]) {
    testAging();
    exit();
}
