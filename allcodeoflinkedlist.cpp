#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void create();
void display();
int main()
{
    int check=1,n;
    do
    {
        printf("1-To create linked list\n");
        printf("2-To display the list\n");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            default:
                check = 0;
        }
    } while (check);    
}
void create()
{
	struct node *temp,*ptr;
	int i,n;
	for(i=0;i<5;i++)
	{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data of the node\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	start=temp;
	else
	{
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=temp;
}
}
}
void display()
{
	struct node *ptr;
	if(ptr==NULL)
	printf("The node is empty\n");
	else
{
	ptr=start;
	while(ptr!=NULL)
	printf("The value of the node is : %d\n",ptr->data);
	ptr=ptr->next;
}
}
