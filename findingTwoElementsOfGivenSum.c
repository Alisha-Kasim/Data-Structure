#include<stdio.h>
#define MAX 9
void findSumNumber(int sum, int size, int *arr)
{
	int temp = 0;
	int index;
	int hash[MAX] = {0};

	for(index = 0 ; index<size ; index++)
	{
		temp = sum - arr[index];
		if(temp >= 0 && hash[temp] == 1 )
		{
			printf("(%d,%d)\n", arr[index] , temp);

		 } 
		 else
		 {
		 	hash[arr[index]]  = 1;

		
		 }
		 
	}
	
	
}


void main()
{
	int i;
	int a[] = {1,2,3,4,5,6,7,8,9};

	int size = 9;
	int sum = 7;
	findSumNumber(sum , size, &a[i]);
}
