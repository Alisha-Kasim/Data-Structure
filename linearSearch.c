#include<stdio.h>

int LinearSearch(int *a, int NumberToBeSearched )
{
	int index=0;
	for(index =0; index < 10; index++)
	{
	
		if(a[index] == NumberToBeSearched)
			return (printf("Number is present at index %d", index));
	}
	
			return(printf("Not present"));
	 		
	

}

void main()
{

	int b, i;

	int a[10] = {1,2,3,4,5,67,89,54,23,21};
	
	printf("Enter number to search ");
	scanf("%d", &b);
	LinearSearch(&a[i], b);
}

