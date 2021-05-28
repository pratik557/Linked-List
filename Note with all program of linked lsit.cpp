#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void createlist();
void displaylist();
void insert_beg();
void insert_end();
void insert_point();
void delete_beg();
void delete_end();
void deletelist();
void sorting();
void traverse();
int main()
{
	int ch,num;
	while(1)
	{
		printf("*********HELLO*********\n");
		printf("1.To create the list \n");
		printf("2.To display the list\n");
		printf("3.To insert the beginnig\n");
		printf("4.To insert at the end \n");
        printf("5.To insert at any point \n");
		printf("6.To delete the beginning\n");
        printf("7.To delete the end\n");
		printf("8.The list is deleted\n");
		printf("9.To sort the element\n");
		printf("10.traversing a linked list\n");
        printf("11.EXIT\n");
		scanf("%d",&ch);
		switch (ch)
		{
		case 1:
			createlist();
			break;
		case 2:
			displaylist();
			break;
		case 3:
		    insert_beg();
			break;
		case 4:
		    insert_end();
		    break;
		case 5:
	        insert_point();
		    break;
		case 6:
		    delete_beg();
		    break;
		case 7:
		    delete_end();
		    break;
		case 8:
		    delete_end();
		    printf("The list is deleted\n");
		    break;
		case 9:
		    sorting();
		    break;
		case 10:
		    traverse();
		    break;
		case 11:
			exit(1);
		default:
			printf("wrong choice");
		}
	}
	return 0;
}
void createlist()
{
	struct node *temp,*ptr;
	for(int i=0;i<4;i++)
	{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the value of node:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	start=temp;
	else
	{
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=temp; //here ptr is equal to start and when the loop goes to enter the 2nd value of the node then start(ptr)->next
	temp->next=NULL;//carry the value of the temp which is newnode for 2nd data.         
}
}
}
void displaylist()
{
	struct node *ptr;
	{
		ptr=start;
		while(ptr!=NULL)
		{
		printf("The value of the node is: %d\n ",ptr->data);
		ptr=ptr->next;              //here,I say ptr to run the loop upto NULL and show me the all data during compile time.
	}
	}
}
void insert_beg()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter new value of the node for the beginning: \n");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;           //here,I created newnode and kept the value of newnode to the start point.
}
void insert_end()
{
	struct node *ptr,*newnode1;
	newnode1=(struct node*)malloc(sizeof(struct node));
	printf("Enter new value for the end node : \n");
	scanf("%d",&newnode1->data);
	newnode1->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=newnode1;      //here,I again created a newnode1 and kept the value of the newnode1 at the end.
}
void insert_point()
{
	struct node *newnode2,*ptr;
	int num;
	printf("enter the point you want to enter\n");
	scanf("%d",&num);
	ptr=start;
	for (int i=1;i<num-1;i++)
	{
		ptr=ptr->next;
	}
	newnode2=(struct node*) malloc (sizeof (struct node));
	printf("enter the new value for the node : ");
	scanf("%d",&newnode2->data);
	newnode2->next=ptr->next;
	ptr->next=newnode2;
}
void delete_beg()
{
	struct node *ptr;
	ptr=start;
	start=start->next; //here,we can not free start.So, initilizing start with ptr and pointing start as start->next.
	free(ptr);         // Then,we can free(ptr).
}
void delete_end()
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;     //Here,we have to initilize preptr to store the value of the 2nd last end node which is ptr then, 
		ptr=ptr->next;  //ptr will carry end node value by which we can free(ptr).
	}
	preptr->next=NULL;
	free(ptr);
}
void deletelist()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		free(ptr);
	}
}
void sorting()  //sorting means arranging the value from lower to higher
{
	struct node *temp,*ptr,*preptr;
	int temp1;
	ptr=temp;
	while(ptr->next!=NULL)
	{
	preptr=ptr->next;// preptr carry the address of the ptr->next
	while(preptr!=NULL)
	{
		if (ptr->data > preptr->data)
		{
			temp1=ptr->data; //temp1 is used for swapping of the variable.
			ptr->data=preptr->data;
			preptr->data=temp1;   //here we are swapping the higher value with lower value.
			
		}
		preptr=preptr->next; //it took forward to preptr->next upto when preptr!=NULl
	}
	 ptr=ptr->next; //it took forward to ptr->next upto when ptr!=NULl
	}
void traverse()  
{  
        struct node *ptr;     
        ptr = start;   
        if(ptr == NULL)  
        {  
            printf("Empty list..");  
        }  
        else  
        {  
            printf("printing values\n");   
            while (ptr!=NULL)  
            {  
                printf("\n%d",ptr->data);  
                ptr = ptr -> next;  
            }  
        }  
}  
