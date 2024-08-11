#include "types.h"
#include "user.h"

void testLotteryScheduler(void) {
    printf(1, "Starting lottery scheduler test...\n");

    int i, pid;
    int num_procs = 5; // Number of processes to test
    int priorities[] = {0, 5, 10, 15, 20}; // Different priorities for processes

    // Set up processes with different priorities
    for (i = 0; i < num_procs; i++) {
        pid = fork();
        if (pid < 0) {
            printf(2, "Error in fork()\n");
            exit();
        } else if (pid == 0) {
            // In the child process
            setpriority(priorities[i]); // Set process priority
            printf(1, "Child process %d with priority %d started.\n", getpid(), priorities[i]);

            // Simulate some work
            for (int j = 0; j < 1000000; j++) {
                asm("nop");
            }

            printf(1, "Child process %d with priority %d finished.\n", getpid(), priorities[i]);
            exit();
        }
    }

    // In the parent process
    for (i = 0; i < num_procs; i++) {
        int ret_pid = wait();
        printf(1, "Parent: Child with PID %d has finished.\n", ret_pid);
    }

    printf(1, "Lottery scheduler test completed.\n");
}

int main(int argc, char *argv[]) {
    testLotteryScheduler();
    exit();
}
