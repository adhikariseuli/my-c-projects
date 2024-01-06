#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ERROR -999
struct node {
	int data;
	struct node *next;
};

struct node *head;

void Push(int val);
int Pop();
void Display();

int main()
{
	int c,val;
	head = NULL;
	do
	{
		printf("\n****************MANUE****************\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the element");
				scanf("%d",&val);
				Push(val);
				break;
			case 2:
				val=Pop();
				if(val!=ERROR)
				    printf("Poped element is %d\n",val);
				break;
			case 3:
				Display();
				break;
			case 4:
				break;
		}
	}while(c!=4);
	return 0;
}

void Push(int val)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=val;
	if(head==NULL)
	 t->next=NULL;
	else{
	 t->next=head;
	 head = t;}
}

int Pop()
{
	int val;
	struct node *t;
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return ERROR;
	}
	else
	{
		val = head->data;
		t=head;
		head=head->next;
		free(t);
		return val;
	}
}

void Display()
{
	struct node *t=head;
	while(t!=NULL)
	{
		printf("%d\n",t->data);
		t=t->next;
	}
	printf("\n");
}
