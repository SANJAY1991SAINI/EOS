2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int ret1,ret2,ret3, s1,s2,s3;

ret1 = fork();
if(ret1 == 0)
{
	ret2 = fork();
	if(ret2 == 0)
	{
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
		for(int i=1; i<=5; i++)
                        {
                        printf("child2: %d\n", i);
                        sleep(1);
                        }
		waitpid(ret3, &s3, 0);
		printf("----------------------\n");
		_exit(0);
	}
	for(int i=1; i<=5; i++)
        	{
                printf("child1: %d\n", i);
                sleep(1);
                }
       waitpid(ret2, &s2, 0);
       printf("----------------------\n");
       _exit(0);
}
for(int i=1; i<=5; i++)
	{
        printf("parent: %d\n", i);
        sleep(1);
        }
waitpid(ret1, &s1, 0);
_exit(0);
}
