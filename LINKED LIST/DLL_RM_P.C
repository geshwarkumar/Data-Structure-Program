/*PROGRAM TO DELETE AN ELELEMENT AT PARTICULAR POSITION FROM THE DOUBLY LINKED LIST
-GESHWAR KUMAR
-12/04/2016*/

/*HEADER FILES*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*STRUCTURE DECLARATION FOR NODE*/
struct node
{
	int data;
	struct node *next,*prev;
};

/*STRUCTURE DELCARATION FOR LIST*/
typedef struct
{
	struct node *start;
}list;

/*FUNCTION DECLARATION */
void INST_LOC(list *,int ); //FOR INSERT ELEMENT
void DEL_LOC(list *);		//DELETION OPERATION
void DISP(list *);	//FOR DISPLAY ELEMENTS

/*MAIN FUNCTION*/
int main()
{
	  list ls;
	  ls.start = NULL; //SET NULL VALUE IN START
//clrscr();
	  /*FUNCTION CALLING FOR INSERT ELEMENT*/
	  INST_LOC(&ls,10);
	  INST_LOC(&ls,20);
	  INST_LOC(&ls,30);
	  //INST_LOC(&ls,40);

	  /*FUNCTION CALLING FOR DISPLAY*/
	  printf("\n Before Deletion :\n");
	  DISP(&ls);

	  /*FUNCTION CALLING FRO DELETION OERATION*/
	  DEL_LOC(&ls);
	  /*FUNCTION CALLING FOR DISPLAY*/
	  printf("\n After Deletion :\n");
	  DISP(&ls);


//system("pause");
return 0 ;
}
/*FUNCTION DECLARATION FOR INSERT ELEMENT*/
void INST_LOC(list *ls,int item)
{
	struct node *newnode,*back,*forw,*num_node;
	int loc,t_node=0,count=1;

	newnode = (struct node *) malloc(sizeof(struct node));

	newnode->data = item ;

	if(ls->start == NULL)
	{
		newnode->prev = NULL ;
		newnode->next = NULL ;
		ls->start = newnode ;
		return;
	}

	num_node = ls->start ;
	while(num_node != NULL)
	{
		t_node ++ ;
		num_node = num_node->next ;
	}
	printf("\n No. of node : %d",t_node);
	printf("\n Enter the location which you want to insert element:(1-%d)::",t_node);
	scanf("%d",&loc);
	if(loc == 1)
	{
		forw = ls->start ;
		newnode->prev = NULL ;
		newnode->next = forw ;
		ls->start = newnode ;
		printf("Values : newnode = %d\t forw = %d",newnode->data,forw->data);
	}
	else if(loc > t_node && (t_node + 2) > loc)
	{
		back = ls->start ;
		printf("Before loop Values : back = %d",back->data);
		while(back->next != NULL)
		{
			back = back->next ;
		}
		printf("\nAfter loop Values : back = %d",back->data);
		back->next = newnode ;
		newnode->next = NULL ;
		newnode->prev = back ;
		//back->prev = NULL ;
		printf("\nAfter Values :newnode=%d back = %d",newnode->data,back->data);

	}
	else if(loc > 1 && loc < t_node)
	{
		forw = ls->start ;
		printf("\nBefore_T Values : forw=%d",forw->data);
		while(count != loc) 	//FOR TRAVERS IN LAST NODE
		{
			back =forw ;
			forw =forw->next ;
			count++;
		}
		printf("\nAfter_T Values : back=%d\t forw=%d",back->data,forw->data);
		newnode->prev = back ;
		newnode->next = forw ;
		back->next = newnode ;
		forw->prev = newnode ;
		printf("\nAfter_T Values : newnode=%d\t back=%d\t forw=%d",newnode->data,back->data,forw->data);
	}
	else
	{
		printf("\n Not in range...");
		return ;
	}

}
/*FUNCTION DECLARATION FOR DELETION OPERATION*/
void DEL_LOC(list *ls)
{
	int itemd,countd = 1,locd,td_node ;
	struct node *delitm,*numd_node ;
	delitm = ls->start ;
	if(ls->start == NULL)
	{
		printf("\n List is empty...");
		return ;
	}
	numd_node = ls->start ;
	while(numd_node != NULL)
	{
		td_node ++ ;
		numd_node = numd_node->next ;
	}

	printf("\n No. of node : %d",td_node);
	printf("\n Enter the location which you want to delete:(1-%d)::",td_node);
	scanf("%d",&locd);

	itemd = delitm->data ; //DELETED NODE

	if(locd == 1 && countd == 1)
	{
	  ls->start = NULL ;
	}
	else if(locd == 1 && countd != 1)
	{
	   delitm->next->prev = NULL ;
	   ls->start = delitm->next ;
	}
	free(delitm);

}
/*FUNCTION DECLARATION FOR DISPLAY*/
void DISP(list *ls)
{
	struct node *temp;      //STRCUTRE OBJECT DECLARATION FOR NODE
	int no_node=0;
	temp = ls->start;	//SET ADDRESS OF START IN TEMP NODE

	/*CHECK LIST IS EMPTY*/
	if(ls->start == NULL)
	{
		printf("\n List is empty...");
		return;
	}

	printf("\n\n Remaining elements are :\n");
	/*OUTPUT STATEMENT*/
	while(temp != NULL)
	{
		printf("%3d",temp->data);
		temp = temp->next;
		no_node++;
	}
	printf("\n Total no of node : %d",no_node);
	free(temp); //FREE MEMORY
}





