//Create a server that accept multiple clients connected over UNIX sockets. Each client send two numbers, server do the addition and send the result back.
//The client connection should be closed immediately after sending response.

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd, x,y,a,b,Fd,sum;
	fd = open("fifo1", O_WRONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);

	a = write(fd, &x, sizeof(x));
	b = write(fd, &y, sizeof(y));
	printf("%d and %d sent\n", x,y);

	Fd = open("fifo2", O_RDONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	read(Fd, &sum, sizeof(sum));
	printf("Sum = %d\n", sum);

	close(fd);
	return 0;
}

