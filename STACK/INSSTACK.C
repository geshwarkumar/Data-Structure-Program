/*Program to implement of insertion in a stack
-Geshwar Kumar
-19/01/2016*/

#include<stdio.h>
#include<conio.h>

void main()
{
	int stk[5],iter,top=0,item,max=5;
	clrscr();
	/*Method for inert a element in a stack*/
	if(top==max)
	{
		printf("Stack is full...");
		exit(0);
	}
	else
	{
		 //top=top+1;
	/*Input operation*/
	for(iter=0;iter<max;iter++)
	{
		top=top+1;

		printf("Enter the element : ");
		scanf("%d",&item);
		stk[iter]=item ;
		if(top==max)
		{
			printf("Stack is full...");
		}
			//top=top+1;
	}
	/*Output operation*/
	printf("\n Input elements are :\n");
	for(iter=0;iter<max;iter++)
	{
		printf("%3d",stk[iter]);
			//top=top+1;
	}
	}

getch();
}