/*Program to insert an element in a stack using array
-Geshwar Kumar
-19/01/2016*/
#include<stdio.h>
#include<conio.h>
#define MAX 5

void main()
{       	//main function open
	int stack[MAX],tos=-1,item,iter;
	clrscr();
	/*Method for isert an element in a satck*/
	if(tos==MAX)
	{
		printf("\n Stack is full...\ncan not be more element stored.");
		exit(0);
	}
	else
	{
		/*Input operation*/
		for(iter=tos+1;iter<MAX;iter++,tos++)
		{
			//tos=tos+1;
			printf("\n Enter element in %d position : ",tos+1);
			scanf("%d",&item);
			stack[tos]=item;
		}
		/*Output operation*/
		printf("\n Entered elements are :\n");
		for(iter=tos;iter>MAX;iter--,tos++)
		{
			printf("%3d",stack[tos]);
			//tos=tos-1;
		}
	}
getch();
}	//End main function
