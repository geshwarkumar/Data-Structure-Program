/* Program to implement different operation on a circular queue
-Geshwar Kumar
-09/02/2016*/

#include<stdio.h>
#define MAX 5
/*Structure declaration*/
typedef struct
{
	int que[MAX];
	int F,R;
}queue;
/*FUNCTION DECLARATION*/
void INSERT(queue *,int);
void DELET(queue *);
void DISPLAY(queue);

/*MAIN FUNCTION*/
int main()
{
	queue q;
	q.F=-1;
	q.R=-1;
	/*FUNCTION CALL*/
	INSERT(&q,10);
	INSERT(&q,20);
	INSERT(&q,30);
	INSERT(&q,40);
	INSERT(&q,50);
	DISPLAY(q);
	DELET(&q);
	DISPLAY(q);
	INSERT(&q,60);
	DISPLAY(q);
	INSERT(&q,70);
return 0 ;
}
/*FUNCTION DEFINITION FOR INSERT*/
void INSERT(queue *q,int item)
{
int item1;
	if(q->F == q->R+1)
	{
		printf("\n Queue is Overflow...");
	return;
	}
	if(q->R==-1)
	{
		q->F=0;
		q->R=0;
	}
	else
	{
		q->R=(q->R+1)% MAX;
	}
	q->que[q->R]=item;
	printf("\n Inserted element is %d in position %d.",q->que[q->R],q->R);
}
/*FUNCTION DEFINITION FOR DELETE ELEMENT*/
void DELET(queue *q)
{
	int item=0;
	item=q->que[q->F];
	printf("\n Deleted element is %d in position %d.",item,q->F);
	if(q->F==q->R)
	{
		q->F=-1;
		q->R=-1;
	}
	else
	{
		q->F=(q->F+1)%MAX;
	}
}
/*FUNCTION DEFINITION FOR DISPLAY */
void DISPLAY(queue q)
{
	if(q.F==-1 && q.R==-1)
	{
		printf("\n Empty queue...!!!");
	return;
	}
	printf("\n Given elements are:\n");

	while(q.F!=q.R)
	{
		printf("\n%d->%d",q.que[q.F],q.F);
		if(q.F==MAX-1)
		{
			q.F=(q.F+1) % MAX;
		}
		else
		{
			q.F++;
		}
	}
	if(q.F==q.R)
	{
		printf("\n%d->%d",q.que[q.F],q.F);
	}
}
