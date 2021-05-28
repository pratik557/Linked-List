#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *start=NULL;
void createlist(int n);
void displaylist();
void insert(int num);
void insertatbeg(int num);
void insertionatend(int num);
int main()
{
	int n,num;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	createlist(n);
	printf("enter the node/position you want to insert");
	scanf("%d",&num);
	if (num==1)
	{
		insertatbeg(num);
	}
	else if (num==n)
	{
		insertionatend(num);
	}
	else
	{
	insert(num);	
	}
	printf("displaying the list\n");
	displaylist();
	return 0;
}
void createlist(int n)
{
	struct node *newnode,*temp;
	int data1,i;
	if (start==NULL || n==0 )
	{
		printf("memory can't be allocated");
		exit(0);
	}
	else 
	{
		start=(struct node*) malloc (sizeof(struct node));
		printf("enter the first value at the node 1:");
		scanf("%d",&data1);
		start->data=data1;
		start->next=NULL;
		temp=start;
	}
	for (i=2;i<=n;i++)
	{
		newnode=(struct node*) malloc (sizeof (struct node));
		if (newnode==NULL)
		{
			printf("memory can't be allocated");
			break;
		}
		else
		{
			printf("enter the value at the node %d:",i);
			scanf("%d",&data1);
			newnode->data=data1;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void displaylist()
{
	struct node *tmp;
	if (start==NULL)
	{
		printf("the list is empty");
	}
	else 
	{
		tmp=start;
		while (tmp !=NULL)
		{
			printf("data is %d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
void insert(int num)
{
	int data2,i;
	printf("enter the  data\n");
	scanf("%d",&data2);
	struct node *tempnode,*ptr;
	ptr=start;
	for (i=1;i<num-1;i++)
	{
		ptr=ptr->next;
	}
	tempnode=(struct node*) malloc (sizeof (struct node));
	tempnode->data=data2;
	tempnode->next=ptr->next;
	ptr->next=tempnode;
}
void insertatbeg(int num)
{
	int data2;
	printf("enter the data to insert");
	scanf("%d",&data2);
	struct node *tmp;
	tmp=(struct node*) malloc (sizeof (struct node));
	tmp->next=start;
	tmp->data=data2;
	start=tmp;
}
void insertionatend(int num)
{
	struct node *ptr,*tempnode;
	printf("enter the data \n");
	int data2;
	scanf("%d",&data2);
	ptr=start;
	while (ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	tempnode=(struct node*) malloc (sizeof(struct node));
	tempnode->data=data2;
	tempnode->next=NULL;
	ptr->next=tempnode;
}
