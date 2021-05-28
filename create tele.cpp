#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void createlist()
{
	struct node *temp,*ptr;
	int i;
	for(i=0;i<5;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the node to be enter\n");
		scanf("%d",&temp->data);
		if(start==NULL)
		start=temp;
		else
		{
			ptr=start;
			ptr=ptr->next;
			ptr->next=temp;
		}
	}
}
void displaylist()
{
	struct node *ptr;
	if(ptr==NULL)
	printf("the node is empty\n");
	else
	{
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
		printf("the list is:%d",ptr->data);
	}
	
}
int main()
{
	createlist();
	displaylist();
	return 0;
}
