#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *start);
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
		    start=create_ll(start);
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

struct node *create_ll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter –1 to end");
printf("\n Enter the data : ");
scanf("%d", &num);
while(num!= –1)
{
 if(start == NULL)
 {
 new_node = (struct node*)malloc(sizeof(struct node));
 new_node -> prev = NULL;
 new_node -> data = num;
 new_node -> next = NULL;
 start = new_node; 
 }
 else
 {
 ptr=start;
 new_node = (struct node*)malloc(sizeof(struct node));
 new_node–>data=num;
 while(ptr–>next!=NULL)
 ptr = ptr–>next;
 ptr–>next = new_node;
 new_node–>prev=ptr;
 new_node–>next=NULL;
 }
 printf("\n Enter the data : ");
 scanf("%d", &num);
}
return start;
}
struct node *display(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr!=NULL)
{
 printf("\t %d", ptr -> data);
 ptr = ptr -> next;
}
return start;
}
