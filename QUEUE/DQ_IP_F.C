/*Program to implement Double indent queue at I/P restricted at FRONT END
-Geshwar Kumar
-17/02/2016*/

#include<stdio.h>
#include<conio.h>

#define MAX 5

/*STRUCTURE VARIABLE FOR DOUBLE INDENT QUEUE*/
typedef struct
{
	int data[MAX];
	int F,R;
}dqueue;

/*FUNCTION DECLARATION */
void INS_F(dqueue *,int); //INSERT IN FRONT END
void DEL_R(dqueue *);     //DELETE FROM REAR END
void DEL_F(dqueue *);     //DELETE FROM FRONT END
void DISP(dqueue);        //DISPLAY FUNCTION

/*MAIN FUNCTION*/
int main()
{
	dqueue dq;
	dq.R=-1;
	dq.F=-1;
	/*FUNCTIONS CALL*/
	INS_F(&dq,11);
	INS_F(&dq,22);
	INS_F(&dq,33);

	DEL_R(&dq);
	DEL_F(&dq);

	DISP(dq);
//getch();
}       //END MAIN
/*INSERT FUNCTION DEFINITION*/
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
/*DELETE FUNCTION DEFINITION*/
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
/*DISPLAY FUNCTION DEFINITION*/
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
