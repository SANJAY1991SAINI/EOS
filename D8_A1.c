#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int ret1,ret2,ret3,i,s,child_pid;

ret1 = fork();

if(ret1 == 0)
	{
	for(int i=1; i<=5; i++)
        	{
                printf("child1: %d\n", i);
                sleep(1);
                }
                _exit(0);
	}
ret2 = fork();
if(ret2 == 0)
        {
        for(int i=1; i<=5; i++)
                {
                printf("child2: %d\n", i);
                sleep(1);
                }
                _exit(0);
        }
ret3 = fork();
if(ret3 == 0)
        {
        for(int i=1; i<=5; i++)
                {
                printf("child3: %d\n", i);
                sleep(1);
                }
                _exit(0);
        }
for(i=1; i<=3; i++)
	{	
	child_pid = wait(&s);
	printf("child pid: %d\n",child_pid);
	}
	printf("parent: pid=%d\n", getpid());
	printf("parent: parent pid=%d\n", getppid());

return 0;
}
