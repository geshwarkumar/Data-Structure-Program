/*PROGRAM TO DELETE AN ELELEMENT FROM BEGNING IN THE LINKED LIST
-Geshwar Kumar
-19/02/2016*/

#include<stdio.h>
#include<malloc.h>

/*STRUCTURE DECLARATION*/
struct node
{
	int data;
	struct node * next;
};

typedef struct
{
	struct node *start;
}list;

/*FUNCTION DECLARATION*/
void INST_BEG(list *,int); 
void DEL_BEG(list *);   // FOR DELETE ELEMENT
void DISP(list *);          

/*MAIN FUNCTION*/
int main(void)
{
	list ls;     /*STRUCTURE VARIABLE DECLARATION*/

	ls.start=NULL;    /*SET NULL VALUE IN START NODE*/

	/*INSERT FUNCTION CALL*/
	INST_BEG(&ls,10);
	INST_BEG(&ls,20);
	INST_BEG(&ls,30);
		
	/*FUNCTION CALLING FOR DISPLAY*/
	printf("Before deletion value : \n");
	DISP(&ls);
	
	/*FUNCTION CALLING FOR DELETE ELEMENT*/
	DEL_BEG(&ls);
	DEL_BEG(&ls);
	INST_BEG(&ls,40);
	INST_BEG(&ls,50);
	
	/*FUNCTION CALLING FOR DISPLAY*/
	printf("\nAfter deletion value : \n");
	DISP(&ls);
	DEL_BEG(&ls);
	DISP(&ls);
return 0;
}//END MAIN

/*INSERT FUNCTION DEFINITION*/
void INST_BEG(list *ls,int item)
{
	struct node *newnode,*prev;   //STRUCTURE NODE OBJECT
	/*MEMORY ALLOCATION */
	newnode = (struct node *) malloc(sizeof(struct node));

	newnode->data = item;
	printf("\n %d is added in %d",newnode->data,newnode);
     
	if(ls->start == NULL)
	{	
		ls->start = newnode;
		newnode->next = NULL;     //SET NULL VALUE IN NEXT PART OF NEWNODE
	}
	else
	{
	    	newnode->next = ls->start;  //SET THE NULL VALUE IN NEXT PART OF NEWNODE
		ls->start = newnode; 	
	}
}//END INSERT FUNCTION

/*FUNCTION DECLARATION FOR DELETE*/
void DEL_BEG(list *ls)
{
	int item ;
	struct node *delitm ;
	delitm = ls->start ;

	if(ls->start == NULL)
	{
		printf("\n In this list no value...");
		return ;
	}

	item = delitm->data ;
	printf("\nDeleted element are : %d",item);
	delitm = ls->start ;
	ls->start = delitm->next ;

	free(delitm);

}

/*DISPLAY FUNCTION DECLARATION*/
void DISP(list *ls)
{
	struct node *temp; //STRUCTURE NODE OBJECT DECLARATION

	//temp = (struct node *) malloc(sizeof(struct node));

	temp = ls->start;

	/*CHECK LIST IS EMPTY OR NOT*/
	if(ls->start == NULL)
	{
		printf("\n Linked list is empty...");
		return;
	}

	/*DISPLAY ELEMENT*/
	printf("\n Elements are :\n");
	while(temp != NULL)
	{
		printf("%3d",temp->data);
		temp = temp->next ;
	}
	free(temp);
}

