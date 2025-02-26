#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	char command[50];
	pid_t pid = fork();
	if(pid == 0) {
		printf("I am %d and my child is %d\n",getpid(),getppid());
		sprintf(command, "pstree -p -s %d -H %d | grep %d", getpid(),getpid(),getpid());
		execlp("sh", "sh", "-c", command, (char *)NULL);
	}
	else {
		printf("I am %d and my parent is %d\n",getpid(),pid);
		wait(NULL);
	}
	return 0;
}


