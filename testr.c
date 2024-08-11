//chatgpt wrote this test to test the priority scheduler
//more organized and clear to see results

#include "types.h"
#include "user.h"

void test_process(char *name, int iterations) {
    int i;
    for (i = 0; i < iterations; i++) {
        printf(1, "Process %s: iteration %d\n", name, i);
        sleep(100); // Simulate some work by sleeping
        // Yield the CPU to allow the scheduler to switch to another process
    }
    exit(); // Terminate the process when done
}

int main(void) {
    int pid;

    // Create multiple processes
    if ((pid = fork()) == 0) {
        test_process("A", 10); // Process A with 10 iterations
    } else if ((pid = fork()) == 0) {
        test_process("B", 10); // Process B with 10 iterations
    } else if ((pid = fork()) == 0) {
        test_process("C", 10); // Process C with 10 iterations
    } else {
        // Parent waits for all children to finish
        while (wait() > 0);
        printf(1, "All processes completed.\n");
    }

    exit();
}
