#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 
void call_fork(){
	pid_t pid = fork();
	if(pid > 0){
		printf("In parent process\n");
		printf("pid: %d\n",getpid());
		printf("ppid: %d\n",getppid());
		printf("\n");
		wait(&pid);
	}
	else if(pid == 0){
		printf("In child process\n");
		printf("pid: %d\n",getpid());
		printf("ppid: %d\n",getppid());
		printf("\n");
	}
	else{
		printf("Fork unsuccessful!\n");
		printf("\n");
	}
}
int main(){
	call_fork();
	call_fork();
	call_fork();
	return 0;
}