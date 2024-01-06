#include<stdio.h>
#include<stdlib.h>

struct node
       {
        int data;
        struct node *next;
       };
struct node *head;
int creatlist();
int display();

int main(){
    int n;
    printf("how many nodes");
    scanf("%d",&n);
    creatlist(n);
    printf("Data in the list \n");
    display();  
    return 0;
}
int creatlist(int n){
    struct node *newnode,*temp ;
    int data;
    head = (struct node*) malloc(sizeof(struct node));
    if (head==NULL)
    {
        printf("unable to alocate");
        exit(0);
    }
    printf("input data to node 1");
    scanf("%d",&data);
    head->data= data;
    head->next=NULL;
    temp=head;
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            printf("unable to aliocate memory");
            break;
        }
        printf("enter data of node %d",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    return 0;
}
int display(){
    struct node *temp;
    if (head==NULL)
    {
        printf("link list empty");
        //return;
        exit(1);

    }
    temp = head;
    while (temp!=NULL)
    {
        printf("data = %d\n",temp->data);
        temp =temp->next;
    }
    
    return 0;
}
