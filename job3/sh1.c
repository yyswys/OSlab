#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void mysys(char *command)
{
	pid_t pid;
	if(command != NULL) {
		pid = fork();
		if(pid == 0) {
			execl("/bin/sh","sh","-c",command,NULL);
		}
		wait(NULL);
	}
	else {
		printf("error\n");
		exit(0);
	}
}

int main()
{
	char command[1024];
	int count;
	while(1) {
		write(1,">",sizeof(">"));
		count = read(0,command,sizeof(command));
		command[count] = 0;
		mysys(command);
	}
	//printf("------------------------------------------------------\n");
	//mysys("echo HELLO WORLD");
	//printf("------------------------------------------------------\n");
	//mysys("ls / ");
	//printf("------------------------------------------------------\n");
	return 0;
}
