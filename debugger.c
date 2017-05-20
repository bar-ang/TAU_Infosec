#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int pid = getpid();
	printf("my pid is %d\n", pid);
	int fres = fork();
	if(fres == 0){
		execv(argv[1],argv+1);
		return 0;
	}
	
	int status;

	if(ptrace(PTRACE_ATTACH,pid,NULL,NULL) < 0){
        perror("attach");
        return -1;
    }
    waitpid(pid, &status, 0);
    if(WIFEXITED(status))
        return -1;



    //detaching
    if(ptrace(PTRACE_DETACH, pid, NULL, NULL) < 0){
        perror("detach");
        return -1;
    }


	return 0;
}