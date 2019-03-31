/*Program for insert element at the ending of the linked list
-Geshwar Kumar
-20/02/2016*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

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
void INST_END(list *,int); 	
void DISP(list *);          

/*MAIN FUNCTION*/
int main(void)
{
	list ls;     /*STRUCTURE VARIABLE DECLARATION*/
	system("cls");

	ls.start=NULL;    /*SET NULL VALUE IN START NODE*/

	/*INSERT FUNCTION CALL*/
	INST_END(&ls,10);
	INST_END(&ls,20);
	INST_END(&ls,30);

	/*DISPLAY FUNCTION CALL*/
	DISP(&ls);
system("pause");
eturn 0;
}//END MAIN

/*INSERT FUNCTION DEFINITION*/
void INST_END(list *ls,int item)
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
		prev = newnode; 	//PASS THE NODE NEWNODE TO PREV NODE
	}
	else
	{
	    	prev->next = newnode;  //SET THE NEXT PART OF PREVIOUS NODE TO NEWNODE`S ADDRESS
		newnode->next = NULL;  //SET THE NULL VALUE IN NEXT PART OF NEWNODE
		prev = newnode; 	//REPLACE NODE NEWNODE TO PREV NODE
	}
}//END INSERT FUNCTION

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

