//stack using array
#include<stdio.h>
#include<conio.h>
#define MAX 5
void push();
void pop();
void display();
int stack[MAX],top = -1,item;//declearing global variables.


//main function 

int main(){
    int ch;
    do{
        printf("\n\n\n\nStack(usingarray) :-\n\n 1. \t Push\n 2. \t Pop\n 3. \t Display\n 4. \t Exit\n\n Enter your choise -- \t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n\nExit");
            break;
        
        default:
            printf("\n\nInvalid try again! (:\n");
          
        }
    }while (ch != 4);
    return 0;  
}


//push operation

void push(){
    if (top == MAX-1)
    {
        printf("\n\nStack is full");
    }
    else
    {
        printf("\n\n Enter the item\t");
        scanf("%d",&item);
        top++;
        stack[top]=item;
        printf("Item inserted (:");
    }
}


//pop operation

void pop(){
    if (top == -1)
    {
        printf("\n\nStack is Empty! (:");
    }
    else{
        item = stack[top];
        top--;
        printf("\n\nItem %d deleted",item);
    }
}


//display operation  

void display(){
    int i;
    if (top == -1)
    {
        printf("Stack is Empty! (:");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("\n %d",stack[i]);
        }
        
    }
}








