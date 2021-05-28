#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *createdl(struct node *start);
struct node *display(struct node *start);
int main()
{
	int ch,num;
	while(1)
	{
	printf("1.To create the doubly linked list\n");
	printf("2.To display the doubly linked list\n");
	scanf("%d",ch);
	switch(ch)
	{
		case 1:
		    start=createdl(start);
		    printf("enter the value of the node");
		    scanf("%d",&num);
			break;
		case 2:
			display(start);
			break;
		case 3:
			exit(1);
		default:
			printf("wrong choice");
	}
	}
	return 0;
}
struct node *createdl(struct node *start)
{
	struct node *newnode,*ptr;
	int n;
	for(int i=0;i<n;i++)
	printf("enter the node you want: \n");
	scanf("%d",&n);
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data for the node: \n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if (start==NULL)
		{
		start=ptr=newnode;
    	}
		else
		{
		ptr->next=newnode;
		newnode->prev=ptr;
		newnode->next=NULL; 
		}
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
	printf("The value of all node are: %d ",ptr->data);
	ptr=ptr->next; 
    }
    return start;
}

