/*Program to search an element in an array using binary search
-Geshwar Kumar
-12/01/2016*/

#include<stdio.h>

int main()
{
	int arr[10],iter,se,lb=0,ub=9,mid=NULL ;/*se=search elment,lb=lower bound,ub=upper bound,mid=middle value*/
	
	/*Input Operation*/
	printf("\n Enter the 10 element :");
	for(iter = 0 ; iter < 10 ; iter++)
	{
		scanf("%d",&arr[iter]);
	}

	/*Output Operation*/
	printf("\n Entered elements are :\n");
	for(iter = 0 ; iter < 10 ; iter++)
	{
		printf("%d in %d position\n",arr[iter],iter);
	}
	
	/*Input search element*/
	printf("\n Enter the element which you want to search : ");
	scanf("%d",&se);

	while(lb < ub && arr[mid] != se)
	{
		mid = (lb + ub) / 2 ;
	
		/*Method for search element*/
		if(se > arr[mid])
		{
			lb = mid + 1 ;
		}
		else
		{
			ub = mid - 1 ;
		}
	}
	if(se == arr[mid])
		printf("\n %d is found in %d position.",arr[mid],mid);
	else
		printf("\n %d is not found in these array.",se);
return 0 ;
}
