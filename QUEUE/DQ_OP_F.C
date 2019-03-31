/*Program to implement Double indent queue at O/P restricted at FRONT END
-Geshwar Kumar
-18/02/2016*/

#include<stdio.h>
#include<conio.h>

#define MAX 5

typedef struct
{
	int data[MAX];
	int F,R;
}dqueue;

void INS_F(dqueue *,int); //INSERT IN FRONT END
void INS_R(dqueue *,int); //INSERT IN REAR END
void DEL_F(dqueue *);     //DELETE FROM FRONT END
void DISP(dqueue);

void main()
{
	dqueue dq;
	dq.R=-1;
	dq.F=-1;

	INS_F(&dq,11);
	INS_F(&dq,22);

	INS_R(&dq,33);
	INS_R(&dq,44);

	DEL_F(&dq);

	DISP(dq);
getch();
}

void INS_F(dqueue *dq,int item)
{
	if(dq->F == 0)
	{
		printf("\n Queue is overflow.");
		return;
	}
	if(dq->F==-1)
	{
		dq->R += 1;
		dq->F += 1;
	}
	else
	{
		dq->F -= 1;
	}
	dq->data[dq->F]=item;
	printf("\n inserted element is %d in position %d.",dq->data[dq->F],dq->F);
}
void INS_R(dqueue *dq,int item)
{
	if(dq->R == (MAX-1))
	{
		printf("\n Queue is overflow.");
		return;
	}
	if(dq->R==-1)
	{
		dq->R=dq->R+1;
		dq->F=dq->F+1;
	}
	else
	{
		dq->R += 1;
	}
	dq->data[dq->R]=item;
	printf("\n inserted element is %d in position %d.",dq->data[dq->R],dq->R);
}
void DEL_F(dqueue *dq)
{
	int item;
	if(dq->F==-1)
	{
		printf("\n Queue is underflow.");
		return;
	}
	item=dq->data[dq->F];
	printf("\n Deleted element is %d from %d at FRONT END.",item,dq->F);
	if(dq->F==dq->R)
	{
		dq->F=-1;
		dq->R=-1;
	}
	else
	{
		dq->F += 1;
	}
}

void DISP(dqueue dq)
{
	if(dq.F == -1)
	{
		printf("\n Empty queue...");
		return;
	}
	printf("\n Remaining element are:\n");
	while(dq.F <= dq.R)
	{
		printf("%3d",dq.data[dq.F]);
		dq.F++;
	}
}