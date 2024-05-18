//Input signal number and a process id from user. Send given signal to the given process using kill() syscall.

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

int main()
{
	int ret, signum, pid;

	printf("Enter Signal Number: ");
	scanf("%d", &signum);

	printf("Enter Process I'd: ");
	scanf("%d", &pid);

	ret = kill(pid, signum);
	if(ret == 0)
		printf("Signal: %d, send to Process: %d ", signum, pid);

	else
		printf("failed to send signal(%d) to process(%d)",signum, pid);

	return 0;
}
