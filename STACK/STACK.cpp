/*Program to implement different operation on stack
-Geshwar Kumar
-23/01/2016*/

#include<stdio.h>
#define MAX 5

typedef struct
{
	int stk[MAX];
	int tos;
}stack;
void PUSH(stack *,int);
int POP(stack *);
void DISP(stack);

int main()
{
	stack s;
	int pe;

	s.tos=NULL;
	PUSH(&s,10);
	PUSH(&s,20);
	PUSH(&s,30);
	DISP(s);
	pe=POP(&s);

	DISP(s);
return 0 ;
}
/*Push operation*/
void PUSH(stack *s,int x)
{
	if(s->tos==MAX-1)
	{
		printf("\n Stack is full.");
		return;
	}
	s->tos++;
	s->stk[s->tos]=x;
	printf("\n Inserted element is : %d",x);
}
/*Pop operation*/
int POP(stack *s)
{
	int del;
	if(s->tos==NULL)
	{
		printf("\n Stack is empty.");
		return  0;
	}
	del=s->stk[s->tos];
	printf("\n Popped element is %d",del);
	s->tos--;
	return del;
}
/*Display operation*/
void DISP(stack s)
{
	if(s.tos==NULL)
	{
		printf("\n Stack is empty...");
		return;
	}
	printf("\n\n Elements are : \n");
	while(s.tos!=NULL)
	{
		printf(" %d\n",s.stk[s.tos]);
		s.tos--;
	}
}
