#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void display()
{
	struct node *ptr;
if (start==NULL)
printf("empty node");
ptr=start;
while(ptr!=NULL)
{
ptr=ptr->next;
}
}
int main()
{
display();
return 0;
}
