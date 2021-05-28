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
	{
		printf("enter the no. of node you want to enter: \n");
		scanf("%d",&n);
		if (start==NULL)
		{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data for the node: \n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		start=newnode;
    	}
		else
		{
		ptr=start;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data for the node: \n");
		scanf("%d",&newnode->data);
		while(ptr->next!=NULL)
		ptr=ptr->next;     
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
	ptr=ptr->next;  //ptr start haa and ptr apan jabhi tak null na hoi tab tak print kari
    }
    return start;
}

