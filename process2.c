#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void odd(int n, int num[50]) {
	printf("Odd numbers : \n");
	for(int i=0;i<n;i++) {
		if(num[i]%2 != 0) {
			printf("%d\t",num[i]);
		}
	}
	printf("\n");
}

void even(int n, int num[50]) {
	printf("Even numbers : \n");
	for(int i=0;i<n;i++) {
		if(num[i]%2 == 0) {
			printf("%d\t",num[i]);
		}
	}
	printf("\n");
}

int main() {
	int n,num[50];
	pid_t pid1,pid2;
	printf("Enter the value of N : ");
	scanf("%d",&n);
	printf("\n");
	printf("Enter the numbers : \n");
	for(int i=0; i<n ; i++) {
		scanf("%d",&num[i]);
	}
	printf("\n");
	pid1 = fork();
	if(pid1==0) {
		odd(n,num);
		exit(0);
	}
	else if (pid1>0) {
		waitpid(pid1,NULL,0);
	}

	pid2 = fork();
	if(pid2==0) {
		even(n,num);
		exit(0);
	}
	else if (pid2>0) {
		waitpid(pid2,NULL,0);
	}
}