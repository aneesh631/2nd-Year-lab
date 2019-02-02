#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	printf("In server!\n");

	int pid = fork();
	if(pid == 0){
		char *args[] = {"./client",NULL};
		execvp(args[0],args);
	}
	else{
		printf("pid of child: %d\n",getpid());
		wait(&pid);
		printf("Server done!\n");
	}

	return 0;
}