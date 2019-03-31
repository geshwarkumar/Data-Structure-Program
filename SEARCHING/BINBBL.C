/*Program to search an element in an array using binary search
-Geshwar kumar
-12/01/2016*/

#include<stdio.h>
#include<conio.h>
#define MAX 10

void main()
{
	int arr[MAX],iter,se,j,lb=0,ub=9,mid,temp;
	clrscr();
	/*Input operation*/
	printf("Enter the 10 elements:\n");
	for(iter=0;iter<MAX;iter++)
	{
		scanf("%d",&arr[iter]);
	}
	/*Sorting operation*/
	printf("\n Entered array element in an sorting ascending order:\n");
	for(iter=0;iter<MAX;iter++)
	{
		for(j=MAX-iter;j>=0;j--)
		{
			if(arr[j]<arr[j+1])
			{
				continue;
			}
			else if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			else
				continue;
		}
		printf("%3d",arr[iter]);
	}
	/*Input operation */
	printf("\n Enter the element which to search : ");
	scanf("%d",&se);
	//mid=(lb+ub)/2;
	/*Method for binary search*/
	while(lb<ub && arr[mid]!=se)
	{
		mid=(lb+ub)/2;
		if(se>arr[mid])
		{
			lb=mid+1;
		}
		else// if(se<arr[iter])
		{
			ub=mid-1;
		}

	}
	if(se==arr[mid])
		printf("\n Searched element is %d in position %d.",arr[mid],mid);
	else
		printf("\n Not found...");

getch();
}