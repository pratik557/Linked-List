#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *p;
void createlist()
{
    int k, n;
    printf ("Number of nodes: "); 
    scanf ("%d", &n); 
    for (k=0; k<n; k++) 
    { 
        if (k == 0) 
        { 
            head = (struct node *) malloc(sizeof(struct node)); 
            p = head; 
        }
        else 
        { 
            p->next = (struct node *) malloc(sizeof(struct node)); 
            p = p->next; 
        }
        printf("Enter value to node: ",k+1);
        scanf ("%d", &p->data); 
    }
    p->next = NULL;
}
void showlist()
{
    int count = 1; 
    if(head == NULL) 
    { 
        printf("\nEmpty List...\n"); 
        return; 
    }
    p = head; 
    while (p != NULL) 
    { 
        printf ("\nNode: %d: %d", count, p->data); 
        count++; 
        p = p->next; 
    }
    printf ("\n"); 
}
void insertAtBeginning()
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    printf("Enter the new data: "); 
    scanf("%d", &newNode->data); 
    newNode->next = head; 
    head = newNode;
}
void insertAtEnd()
{
    struct node* prev; 
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    printf("Enter the new data: "); 
    scanf("%d", &newNode->data); 
    newNode->next = NULL; 
    prev = head; 
    if (prev == NULL) 
    { 
        head = newNode; 
        return; 
    }
    while (prev->next != NULL)
        prev = prev->next; 
    prev->next = newNode;

}
void insertAtPos()
{
    int pos, i, nodes=0; 
    struct node *newNode, *prev; 
    struct node* curr=head; 
    while(curr != NULL)
    { 
        nodes++; 
        curr=curr->next; 
    } 
    printf("\nEnter the position: "); 
    scanf("%d", &pos); 
    if(pos < 1 || pos > nodes) 
    { 
        printf("Invalid Input..."); 
        return; 
    } 
    newNode =(struct node*) malloc(sizeof(struct node)); 
    printf("\nEnter the new data: "); 
    scanf("%d", &newNode->data); 
    newNode->next=NULL; 
    if(pos==1) 
    { 
        newNode->next=head; 
        head=newNode; 
    }
    i = 1; 
    curr = head; 
    while(i<pos) 
    { 
        i++; 
        prev = curr; 
        curr = curr->next; 
    }
    newNode->next = prev->next; 
    prev->next = newNode;
}
void insertAfter()
{
    int value;
    printf("Enter the value after which you want to enter data: ");
    scanf("%d",&value);
    struct node *ptr=head;
    while(ptr!=NULL && ptr->data!=value)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("%d is not present in the list.\n",value);
        return;
    }

    struct node *node = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data to the node : ");
    scanf("%d",&node->data);
    node->next = ptr->next;
    ptr->next=node;

}

int main()
{
    int check=1,n;
    do
    {
        printf("\n\n\t\tEnter what operation you want to perform\n");
        printf("1-To create linked list\n");
        printf("2-To display the list\n");
        printf("3-To insert node at beginning\n");
        printf("4-To insert node at end\n");
        printf("5-To insert node at specific position\n");
        printf("6-To insert after some value\n");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
                createlist();
                break;
            case 2:
                showlist();
                break;
            case 3:
                insertAtBeginning();
                break;
            case 4:
                insertAtEnd();
                break;
            case 5:
                insertAtPos();
                break;
            case 6:
                insertAfter();
                break;
            default:
                check = 0;
        }
    } while (check);    
}
