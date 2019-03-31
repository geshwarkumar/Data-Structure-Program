/*Program to implement Double indent queue at O/P restricted at REAR END
-Geshwar Kumar
-18/02/2016*/

#include<stdio.h>
#define MAX 5

typedef struct
{
	int data[MAX];
	int F,R;
}dqueue;

void INS_F(dqueue *,int); //INSERT IN FRONT END
void INS_R(dqueue *,int); //INSERT IN REAR END
void DEL_R(dqueue *);     //DELETE FROM REAR END
void DISP(dqueue);

int main()
{
	dqueue dq;
	dq.R=-1;
	dq.F=-1;

	INS_F(&dq,11);
	INS_F(&dq,22);

	INS_R(&dq,33);
	INS_R(&dq,44);

	DEL_R(&dq);

	DISP(dq);
return 0;
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
void DEL_R(dqueue *dq)
{
	int item;
	if(dq->R==-1)
	{
		printf("\n Queue is empty.");
		return;
	}
	item=dq->data[dq->R];
	printf("\n Deleted element is %d from %d at REAR END",item,dq->R);
	if(dq->R==dq->F)
	{
		dq->R=-1;
		dq->F=-1;
	}
	else
	{
		dq->R -= 1;
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
