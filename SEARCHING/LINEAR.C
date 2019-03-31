/*Program to search an element in an array using linear search
-Geshwar Kumar
-12/01/2016*/

#include<stdio.h>

int main()
{
	int arr[10],iter,se ;	//se=search elment
	
	/*Input Operation*/
	printf("\n Enter the 10 element :");
	for(iter=0;iter<10;iter++)
	{
		scanf("%d",&arr[iter]);
	}

	/*Output Operation*/
	printf("\n Entered elements are :\n");
	for(iter=0;iter<10;iter++)
	{
		printf("%d in %d position\n",arr[iter],iter);
	}
	
	/*Input search element*/
	printf("\n Enter the element which you want to search : ");
	scanf("%d",&se);

	iter = 0 ;
	while(iter<10)
	{
		/*Method for search element*/
		if(se==arr[iter])
		{
			printf("\n %d is found in %d position.",arr[iter],iter);
			break;
		}
	iter++ ;
	}
	if(iter==10)
	{
		printf("%d is not found in these array.",se);
	}
return 0 ;
}//END MAIN
