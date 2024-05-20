//. Find the size of pipe buﬀer in your system
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int arr[2];

void sigint_handler(int sig) {
    printf("Signal caught: %d\n", sig);
    close(arr[1]);
    close(arr[0]);
    _exit(0);
}

int main() {
    char ch = 'A';
    int count = 0;
    int ret1 = pipe(arr);

    if (ret1 < 0) {
        perror("pipe() failed");
        _exit(1);
    }

    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    int ret2 = sigaction(SIGINT, &sa, NULL);
	if(ret2<0)
	{
		perror("sigaction failed");
		_exit(1);
	}
    while (1) {
        write(arr[1], &ch, 1);
        count++;
        printf("Bytes written: %d\n", count);
    }

    return 0;
}
