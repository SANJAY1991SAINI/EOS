//The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
//process print the result.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int Fd,fd,a,b,x,y,sum;
	fd = open("fifo1", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	a = read(fd, &x, sizeof(x));
	b = read(fd, &y, sizeof(y));
	printf("read from fifo1: %d and %d\n", x,y);
	sum = x + y;
		
	Fd = open("fifo2", O_WRONLY);
	if(Fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	write(Fd, &sum, sizeof(sum));
	printf("sum sent to client by another fifo: \n");
	close(fd);
	return 0;
}


