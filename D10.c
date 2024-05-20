#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY  0x1234

typedef struct msg 
{
	long type;
	int data[2];
}msg_t;

int main()
{
	int mqid,ret,s,res;
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0)
	{
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if (ret  == 0)
	{
		msg_t m1;
		m1.type = 1;
		printf("sender/child : enter 2 number: ");
		scanf("%d %d",&m1.data[0],&m1.data[1]);
		ret = msgsnd(mqid, &m1,sizeof(m1.data),0);
		printf("sender/child : message sent :%d %d-- %d\n",m1.data[0],m1.data[1],ret);

		ret = msgrcv(mqid,&m1 ,sizeof(m1.data),2,0);
		printf("receiver/child : result received : %d\n",m1.data[0]);
	}
	else
	{
		msg_t m2;

		printf("receiver/parent : waiting for the message...\n");
		ret = msgrcv(mqid, &m2 ,sizeof(m2.data),1,0);
		printf("receiver/parent : message received : %d %d-- %d\n",m2.data[0],m2.data[1],ret);
		
		m2.type=2;
		res = m2.data[0]+m2.data[1];
		m2.data[0]=res;
		ret = msgsnd(mqid, &m2,sizeof(m2.data[0]),0);
		printf("sender/parent : message sent : %d\n",ret);
	}
	wait(&s);
	msgctl(mqid, IPC_RMID, NULL);
	return 0;

}
