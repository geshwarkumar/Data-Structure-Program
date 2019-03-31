/*PROGRAM TO DELETE ELELEMENT FROM END FROM THE DOUBLY LINKED LIST
-GESHWAR KUMAR
-9/04/2016*/

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
void INST_END(list *,int ); //FOR INSERT ELEMENT
void DEL_END(list *); 		//FORM DELETION OPERATION
void DISP(list *);	//FOR DISPLAY ELEMENTS

/*MAIN FUNCTION*/
int main()
{
	  list ls;
	  ls.start = NULL; //SET NULL VALUE IN START
system("cls");
		clrscr();
	  /*FUNCTION CALLING FOR INSERT ELEMENT*/
	  INST_END(&ls,10);
	  INST_END(&ls,20);
	  INST_END(&ls,30);

	  /*FUNCTION CALLING FOR DISPLAY*/
	  printf("\n Before deltion :\n");
	  DISP(&ls);
	  /*FUNCTION CALLING FOR DELTION*/
	  DEL_END(&ls);
	  DEL_END(&ls);

	  /*FUNCTION CALLING FOR DISPLAY*/
	  printf("\n After deltion :\n");
	  DISP(&ls);
//system("pause");
return 0 ;
}
/*FUNCTION DECLARATION FOR INSERT ELEMENT*/
void INST_END(list *ls,int item)
{
	struct node *newnode,*back;

	newnode = (struct node *) malloc(sizeof(struct node));

	newnode->data = item ;
	newnode->next = NULL ;

	if(ls->start == NULL)
	{
		newnode->prev = NULL ;
		ls->start = newnode ;
		return;
	}
	//printf(" %d insert in %d",newnode->data,loc);
	back = ls->start ;
	while(back->next != NULL)
	{
		back = back->next ;
	}
	newnode->prev = back ;
	back->next = newnode ;
	newnode->next = NULL ;
	back->prev = NULL ;
}
/*FUNCTION DECLARATION FOR DELETION*/
void DEL_END(list *ls)
{
	int item ;
	struct node *delitm ;

	if(ls->start == NULL)
	{
		printf("\n In this list no data...");
		return ;
	}
	delitm = ls->start ;   //CONNECT NODE TO LIST

	/*FOR TRAVERSING TO THE LAST NODE*/
	while(delitm->next != NULL)
	{
		delitm = delitm->next ;
	}
	item = delitm->data ;
	printf("\n Deleted item is :%d",item);
	delitm->prev->next = NULL ;
	free(delitm);

}
/*FUNCTION DECLARATION FOR DISPLAY*/
void DISP(list *ls)
{
	struct node *temp;      //STRCUTRE OBJECT DECLARATION FOR NODE

	temp = ls->start;	//SET ADDRESS OF START IN TEMP NODE

	/*CHECK LIST IS EMPTY*/
	if(ls->start == NULL)
	{
		printf("\n List is empty...");
		return;
	}

	printf("\n Remaining elements are :\n");
	/*OUTPUT STATEMENT*/
	while(temp->next != NULL)
	{
		printf("%3d",temp->data);
		temp = temp->next;
	}
	free(temp); //FREE MEMORY
}





