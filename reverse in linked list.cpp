#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *start = NULL;

struct node *reverse (struct node *head, int k)
{
	struct node* curr = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;

	while (curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next != NULL)
	head->next = reverse(next, k);

	return prev;
}

void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                exit(0);
        }
        printf("Enter the data value for the node: ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->data );
                        ptr=ptr->next ;
                }
        }
}

int main()
{
	int cont,k;
    printf("Do you want to enter the value to node?(0/1) ");
    scanf("%d",&cont);
    while(cont == 1)
    {
        create();
        printf("\nDo you want to enter more node?(0/1) ");
        scanf("%d",&cont);
    }
    printf("\nThe list is:\n");
    display();

    printf("\nEnter the value of k: ");
    scanf("%d",&k);
	start = reverse(start, k);

	printf("\nReversed Linked list \n");
	display();

	return 0;
}
