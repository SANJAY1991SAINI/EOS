#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

struct bs
{
	int *arr;
	int size;
};

void* bubble_sort(void *param)
{
	struct bs *ptr = (struct bs*)param;
	int n = ptr->size;
	int *arr = ptr->arr;

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i- 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
	return NULL;
}


int main()
{
	int arr1[]={45,89,75,56,74,23,0,95,156,25};
	int ret;
	int size1 = (sizeof(arr1)/sizeof(arr1[0]));
	
	struct bs array;
	array.arr = arr1;
	array.size = size1;
	
	pthread_t b1;
	ret = pthread_create(&b1,NULL,bubble_sort,&array);
	if(ret < 0)
	{
		perror("create() failed");
		_exit(0);
	}
	
	
	pthread_join(b1,NULL);
	printf("Parent Waiting For Sorted Thread : \n");
	printf("Sorted Array : ");
	for(int i=0; i<size1; i++)
	{
		printf("%d ",arr1[i]);
	}

	printf("\n");
	return 0;
}












