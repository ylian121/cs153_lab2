//example test from lab 1
/*#include "types.h"
#include "user.h"

int main() {

    int child1_pid = fork();    // Parent process creates the first child process
    if (child1_pid == 0) {      // make sure only the child process enters this block     
        sleep(100);             // delay to allow sibiling creation
        getsiblings();          // getsiblings() syscall
        exit(0);                // Exit status added (lab1-part3)
    }

    int child2_pid = fork();
    if (child2_pid == 0) {
        sleep(100);
        exit(0);                // Exit status added (lab1-part3)
    }

    int child3_pid = fork();
    if (child3_pid == 0) {
        sleep(100);
        exit(0);                // Exit status added (lab1-part3)
    }

    // Calling wait syscall ensures the parent process waits for 
    // all child processes to terminate, preventing zombie processes.
    int wait_status;
    int wait_pid; 
    wait_pid = wait(&wait_status);   // Exit status added (lab1-part4)
    wait_pid = wait(&wait_status);   // Exit status added (lab1-part4)
    wait_pid = wait(&wait_status);   // Exit status added (lab1-part4)

    exit(0);                         // Exit status added (lab1-part3)
}
*/

#include "types.h"
#include "user.h"

int priorityScheduler(void);

int main(int argc, char *argv[])
{
    priorityScheduler();
    exit();
}    

//test priority scheduler
//assuming that the priorities range between range between 0 to 30
//0 is the highest priority. 30 is the lowest.
//all processes have a default priority of 10 

int priorityScheduler(void){
		 
    printf(1, "test priority scheduler\n");

    int pid, ret_pid;
    int i,j,k; 

    //set parent to highest - 0
    setpriority(0);

    for(i = 0; i < 3; i++){
        //new process
        pid = fork();
        //continue to work
        if (pid > 0) {
            continue;
        } else if(pid == 0){
            printf(1, "Child# %d - change priority to %d \n", getpid(), 30 - 10 * i);
            //set child priority
            setpriority(30 - 10 * i);
            for(j = 0; j < 50000; j++){
                asm("nop");
                for(k = 0; k < 10000; k++) {
                    asm("nop"); 
                }
            }
            //finished and exit
            printf(1, " - Child #%d with priority %d has finished! \n", getpid(), 30-10*i);		
            exit();
        } else{
            printf(2," \n Error fork() \n");
            exit();
        }
    }

    if(pid > 0) {
        for (i = 0; i < 3; i++) {
            ret_pid = wait();
            printf(1, " - This is the parent: child with PID# %d has finished\n", ret_pid);
        }
        printf(1, " - If processes with highest priority finished first then its correct. \n");
    }
			
    return 0;
}