/*Program to check string is palindrome or not using the stack
-Geshwar Kumar
-05/02/2016*/

#include<stdio.h>
#include<string.h>
#define MAX 5

typedef struct
{
	int stk[MAX];
	int tos;
}stack;

void PUSH(stack *,char);
int POP(stack *);
void DISP(stack);

int main()
{
	stack s;
	int iter=0;
	char str1[10],str2[10];
	
	s.tos=-1;

	printf("\n Enter the element : ");
	gets(str1);
	while(str1[iter]!='\0')
	{
		PUSH(&s,str1[iter]);
		iter++;
	}
	iter=0;
	while(s.tos!=-1)
	{
		str2[iter]=POP(&s);
		iter++;
	}
	str2[iter]='\0';
	printf("\n\n ~~~RESULTS~~~\n");
		if(strcmp(str1,str2) == 0)
			printf(" Given string is pallindrome.");
		else
			printf(" Not pallindrome.");
	DISP(s);
return 0 ;
}
/*Push operation*/
void PUSH(stack *s,char x)
{
	if(s->tos==MAX-1)
	{
		printf("\n Stack is full.");
		return;
	}
	s->tos++;
	s->stk[s->tos]=x;
	printf("\n Inserted element is : %c",x);
}
/*Pop operation*/
int POP(stack *s)
{
	int del;
	if(s->tos==-1)
	{
		printf("\n Stack is empty.");
		return 0;
	}
	del=s->stk[s->tos];
	printf("\n Popped element is %c",del);
	s->tos--;
	return del;
}
/*Display operation*/
void DISP(stack s)
{
	//int iter=0;
	if(s.tos==-1)
	{
		printf("\n\n\n Stack is empty...stack is free...");
		return ;
	}
}
