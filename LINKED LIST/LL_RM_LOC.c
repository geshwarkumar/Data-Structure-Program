/*PROGRAM FOR DELETE ELEMENT IN PARTICULAR POSTION INTO THE LINKED LIST
-GESHWAR KUMAR
-20/02/2016 */

/*HEADER FILES INCLUDE*/
#include<stdio.h>
#include<stdlib.h>

#include<malloc.h>     //FOR DYNAMICALLY MEMEORY ALLOCATION FUNCTION

/*STRUCTURE VARIABLE DECLARATION (SELF DEFENCE) FOR NODE*/
struct node
{
 	  int data;   //FOR DATA PART  (CONTAIN THE VALUE)
 	  struct node *next; //FOR NEXT PART (COTAIN THE ADDRESS OF NEXT NODE)
};

/*STRUCTURE DECLARATION FOR LIST*/
typedef struct
{
 	   struct node *start;
}list;

/*FUNCTION DECLARATION*/
void INS_LOC(list *,int);  //FOR INSERT ELEMENT
void DEL_LOC(list *);	//DELETION OPERATION
void DISP(list *);      //FOR DISPLAY ELEMENT

/*MAIN FUNCTION*/
int main(void)
{
    list ls;     //STRUCTURE OBJECT DECLARATION
system("cls");
    		    
    ls.start = NULL; //SET NULL VALUE IN START
    		    
    /*FUNCTION CALL FOR INSERT ELEMENT*/
    INS_LOC(&ls,10);
    INS_LOC(&ls,20);
    INS_LOC(&ls,30);
    
    /*FUNCTION CALLING FOR DISPLAY*/
	printf("\n Before Deletion :\n");
	DISP(&ls);
	    
    /*FUNCTION CALLING FRO DELETION OERATION*/
	DEL_LOC(&ls);
	INS_LOC(&ls,40);
    INS_LOC(&ls,50);
	/*FUNCTION CALLING FOR DISPLAY*/
	printf("\n After Deletion :\n");
	DISP(&ls);
    DEL_LOC(&ls);		    
    DISP(&ls);
system("pause");
return 0;
}
/*FUNCTION DEFINITION FOR INSERT ELELEMENT*/
void INS_LOC(list *ls,int item)
{
 	struct node *prev,*newnode,*forw;	//STRUCTURE OBJECT/VARIABLE
	int loc,count = 0 ;         //FLAG/COUNT VARIABLE FOR COUNT POSTION OF ALL INSERTED ELEMENT
		    
	newnode = (struct node *) malloc(sizeof(struct node));	//MEMEORY ALLOCATE FOR LINKED LIST
 	newnode = ls->start;
 		    
 	newnode->data = item; 
 	printf("\n Inserted element is %d in %d.",newnode->data,newnode);
 		    
	if(ls->start == NULL)    //CHECK LIST IS EMPTY OR NOT
 	{
		newnode->next = NULL ;
 		prev = newnode ;
    }
    else
    {
		while(newnode->next != NULL)
 	   	{
		    count++ ;
		}
		if(count == 1)
		{
			newnode->next = NULL ;
			prev->next = newnode ;
			forw = newnode ;
		}
		else
		{
			printf("\n Enter the position where insert your element : ");
 			scanf("%d",&loc);
			if(count == loc)
			{
		 	    prev->next = newnode ;
			    forw = newnode ;
	        }
        }
    }
}

/*FUNCTION DECLARATION FOR DELETION OPERATION*/
void DEL_LOC(list *ls)
{
	int itemd,countd = 1,locd,td_node ;
	struct node *delitm,*numd_node,*temp ;
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

	if(locd == 1) 
	{
	  delitm = ls->start ;
	  ls->start = ls->start->next ;
	  
	}
	else
	{
	   delitm = ls->start ;
	   while(countd < locd && delitm != NULL)
		{
			temp = delitm ;
			delitm = delitm->next ;
			countd++ ;
		}
	   temp->next = delitm->next ;
	}
	free(delitm);
}

/*FUNCTION DEFINITION FOR DISPALY ELELEMNTS*/
void DISP(list *ls)
{
 	struct node *temp;
 		
 	temp = ls->start ;
 		
 	if(ls->start ==  NULL)
 	{
	   printf("\n List is empty...");
	   return;
    }
    printf("\n Elements are :\n");
    while(temp != NULL)
    {
		printf("%3d",temp->data);
		temp = temp->next ;
    }
    free(temp);          
}   
