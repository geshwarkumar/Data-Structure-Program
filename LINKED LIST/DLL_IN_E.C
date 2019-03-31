/*PROGRAM TO INSERT AN ELELEMENT AT ENDING IN THE DOUBLY LINKED LIST
-GESHWAR KUMAR
-15/03/2016*/

/*HEADER FILES*/
#include<stdio.h>
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
void DISP(list *);	//FOR DISPLAY ELEMENTS

/*MAIN FUNCTION*/
int main()
{
	  list ls;
	  ls.start = NULL; //SET NULL VALUE IN START

	  /*FUNCTION CALLING FOR INSERT ELEMENT*/
	  INST_END(&ls,10);
	  INST_END(&ls,20);
	  INST_END(&ls,30);

	  /*FUNCTION CALLING FOR DISPLAY*/
	  DISP(&ls);
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

	printf("\n Inserted elements are :\n");
	/*OUTPUT STATEMENT*/
	while(temp != NULL)
	{
		printf("%3d",temp->data);
		temp = temp->next;
	}
	free(temp); //FREE MEMORY
}





