#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void create()
{
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof (struct node));
	printf("enter the value of the temp node..");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (start==NULL)
	start=temp;
	else
	{
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=temp;
}
}
void display()
{
struct node *ptr;
if(ptr==NULL)
printf("The list is Empty");
else
{
ptr=start;
while(ptr!=NULL)
{
printf("the given data are:%d",ptr->data);
ptr=ptr->next;
}
}
}
int main()
{
	create();
	display();
	return 0;
}

