//Write a program that compiles above multi-ﬁle project. It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c"
//concurrently.
//parent
//|- child1 (gcc -c circle.c)
//|- child2 (gcc -c square.c)
//|- child3 (gcc -c rectangle.c)
//|- child4 (gcc -c main.c)
//wait for all child and check exit status. If all exit status 0 (success), then link
//|- child5 (gcc -o program.out circle.o square.o rectangle.o main.o)
//wait for child and check exit status. If all exit status 0 (success), then run it.
//|- child6 (./program.out)
//wait for child and check exit status. Then print child exit status.
#include"shape.h"

int main()
{
	printf("Main file\n");
	circle();
	square();
	rectangle();
	return 0;
}
