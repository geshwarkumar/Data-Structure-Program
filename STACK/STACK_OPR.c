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

/*FUNCTION DECLARATION*/
void PUSH(stack *,int);
int POP(stack *);
void DISP(stack);

int main()
{			//MAIN FUNCTION START
	stack s ;	//STRUCTURE OBJECT

	int pe,item,iter ;

	s.tos = NULL ;
	
	/*FUNCTION CALLING*/
	for(iter = 1 ; iter <= MAX ;iter++)
	{
		printf(" Enter element in %d position : ",iter);
		scanf("%d",&item);
		PUSH(&s,item);
	}
	DISP(s);
	//pe=POP(&s);
	//DISP(s);
return 0 ;
}//END MAIN

/*Push operation*/
void PUSH(stack *s,int x)
{
	if(s->tos == MAX)
	{
		printf("Stack is full.");
		return ;
	}
	s->tos++ ;
	s->stk[s->tos] = x ;
	//printf("\n Inserted element is : %d",x);
}

/*Pop operation*/
int POP(stack *s)
{
	int del;
	if(s->tos == NULL)
	{
		printf(" Stack is empty.");
		return  0;
	}
	del = s->stk[s->tos] ;
	printf("\n Popped element is %d",del);
	s->tos-- ;
	return del ;
}

/*Display operation*/
void DISP(stack s)
{
	if(s.tos == NULL)
	{
		printf("\n Stack is empty...");
		return ;
	}
	printf("\n Elements are : \n");
	while(s.tos != NULL)
	{
		printf("%d -> %d\n ",s.tos,s.stk[s.tos]);
		s.tos-- ;
	}
}
