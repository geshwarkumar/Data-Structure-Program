/*Program to delete an element in a stack using array
-Geshwar Kumar
-19/01/2016*/
#include<stdio.h>
#include<conio.h>
#define MAX 5

void main()
{       	//main function open
	int stack[]={11,22,33,44,55};
	int tos=-1,item,iter,n;
	clrscr();
	/*Method for delete an element in a satck*/
	if(tos==-1)
	{
		printf("\n Stack is empty...\ncan not be delete element.");
		exit(0);
	}
	else
	{
		/*Output operation*/
		printf("\n Given elements are :\n");
		for(iter=tos;iter>MAX;iter--,tos++)
		{
			printf("%3d",stack[tos]);
			//tos=tos-1;
		}
		printf("\n How many element delete: ");
		scanf("%d",&n);
		/*Deletion Operation*/
		for(iter=MAX;iter>n+1;iter--,tos--)
		{
			//tos=tos+1;
			item=stack[tos];
			printf("\n Delete element is : %d",item);
		}
		/*Output operation*/
		printf("\n After pop elements are :\n");
		for(iter=tos;iter>MAX;iter--,tos++)
		{
			printf("%3d",stack[tos]);
			//tos=tos-1;
		}
	}


getch();
}	//End main function
