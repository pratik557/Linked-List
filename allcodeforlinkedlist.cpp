#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void create();
void display();
void insert_beg();
void insert_end();
int main()
{
    int check = 1, n;
    do
    {
        printf("1-To create linked list\n");
        printf("2-To display the list\n");
        printf("3-To insert at beg\n");
        printf("4-To insert at end\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_end();
            break;
        default:
            check = 0;
        }
    } while (check);
}
void create()
{
    struct node *temp, *ptr;
    int i;
    for (i=0; i<3; i++)
	{
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the node\n");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            ptr = ptr->next;
            ptr->next = temp;
        }
    }
}
void display()
{
    struct node *ptr;
    if (ptr == NULL)
    printf("The node is empty\n");
	else
    {
        ptr = start;
        while(ptr!=NULL)
        {
        printf("The value of the node is : %d\n", ptr->data);
        ptr = ptr->next;
}
	}
}
void insert_beg()
{
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("Enter the new value for the beg node \n");
    scanf("%d",&newnode->data);
    newnode->next = start;
    start = newnode;
}
void insert_end()
{
    struct node *ptr, *newnode1;
    newnode1= (struct node*)malloc(sizeof(struct node));
    printf("Enter the new value for the end node: ");
    scanf("%d",&newnode1->data);
    newnode1->next = NULL;
    ptr= start;
    while(ptr->next!= NULL)
    ptr=ptr->next;
    ptr->next = newnode1;
}
