/*PROGRAM TO INSERT AN ELELEMENT AT BEGNING IN THE DOUBLY LINKED LIST
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
void INST_BEG(list *,int ); //FOR INSERT ELEMENT
void DISP(list *);	//FOR DISPLAY ELEMENTS

/*MAIN FUNCTION*/
int main()
{
	  list ls;
	  ls.start = NULL; //SET NULL VALUE IN START

	  /*FUNCTION CALLING FOR INSERT ELEMENT*/
	  INST_BEG(&ls,10);
	  INST_BEG(&ls,20);
	  INST_BEG(&ls,30);

	  /*FUNCTION CALLING FOR DISPLAY*/
	  DISP(&ls);

return 0 ;
}
/*FUNCTION DECLARATION FOR INSERT ELEMENT*/
void INST_BEG(list *ls,int item)
{
	struct node *newnode,*back;

	newnode = (struct node *) malloc(sizeof(struct node));

	newnode->data = item ;
	newnode->prev = NULL ;

	if(ls->start == NULL)
	{
		newnode->next = NULL ;
		ls->start = newnode ;
		return;
	}
	//printf(" %d insert in %d",newnode->data,loc);
	back = ls->start ;
	newnode->next = back ;
	back->prev = newnode ;
	ls->start = newnode ;
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





