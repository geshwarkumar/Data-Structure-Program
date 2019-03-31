/*Program to evaluate postfix to infix notation
-Geshwar Kumar
-17/02/2016*/

#include<stdio.h>
#include<conio.h>

#define MAX 5

/*STRUCTURE VARIABLE DECLARATION*/
typedef struct
{
        int data[MAX];
        int tos;
}postfix;

/*FUNCTION DECLARATION*/
void PUSH(postfix *,int);
int POP(postfix *);
void DISP(postfix);

/*MAIN FUNCTION*/
int main()
{
    postfix p;           //STRUCTURE VARIABLE
    char str1[10],str2[10];
    int i = 0;
    p.tos = -1;
    
    printf(" Enter the expression:");
    gets(str1);
    
    /*INPUT THE EXPRESSION INTO THE STSCK*/
    while(str1[i] != '\0')
    {
                  PUSH(&p,str1[i]);
                  i++;
    }
    /*TRANSFER THE RESULT AFTER EVALUATION IN STR2*/
    i=0;
    while(p.tos != -1)
    {
                  str2[i] = POP(&p);
                  i++;
    }
    str1[i] = '\0';
    
    printf("\n Result is:\n The expression in postfix form");puts(str2);
    
    DISP(p);
    
getch();
}
    
    
    
