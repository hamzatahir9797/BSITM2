#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid, pid1, pid2, pid3, pid4, pid5, pid6;
	pid = fork();
	if (pid == 0) {
		sleep(2);
		printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
	}
	else {
		pid1 = fork();
		if (pid1 == 0) {
			sleep(2);
			printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
			    sleep(4);
				printf("child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());
			}
			else {
			    pid3 = fork();
    			if (pid3 == 0) {
    			    sleep(5);
    				printf("child[4] --> pid = %d and ppid = %d\n", getpid(), getppid());
    			}
    			else {
    			    pid4 = fork();
        			if (pid4 == 0) {
        			    sleep(6);
        				printf("child[5] --> pid = %d and ppid = %d\n", getpid(), getppid());
        			}
        			else {
        			    pid5 = fork();
            			if (pid5 == 0) {
            			    sleep(7);
            				printf("child[6] --> pid = %d and ppid = %d\n", getpid(), getppid());
            			}
            			else {
            			    sleep(1);
            				printf("child[7] --> pid = %d and ppid = %d\n", getpid(), getppid());
            				sleep(3);
                            printf("parent --> pid = %d\n", getpid());
            			}
        			}
    			}
			}
		}
	}
	return 0;
}
