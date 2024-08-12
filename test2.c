#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define N 3
//function to print process information 
void print_info(int id, const char *message) {
	printf(1, "Process %d: %s\n", id, message);
}


int main() {
	int pid; 

	printf(1, "Starting priority donation and inheritance test...\n");

	//creating parent process with high priority
	pid = fork();
	if (pid < 0) {
		printf(1, "Fork failed\n");
		exit();
	}

	if (pid == 0) {
		//setting child priority lower 
		setpriority(10); 
		print_info(getpid(), "Child process created with lower priority"); 
		exit(); 
	} else {
		//setting parent priority higher
		setpriority(1); 
		print_info(getpid(), "Parent process created with higher priority"); 
		wait(); 
		print_info(getpid(), "Parent process resumed after child exited"); 

		for (int i = 0; i < 3; i++) {
			pid = fork(); 
			if (pid == 0) {
				print_info(getpid(), "Extra child process running"); 
			exit(); 
			}
		}

		while (wait() > 0) {
		}

		print_info(getpid(), "Parent process exiting"); 
		exit(); 
	}
	//test_priority_inheritance_donation();
	return 0; 
}
