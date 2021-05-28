//Queue implementation using Linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*rear = NULL, *front = NULL;

struct node* newnode(int item){
    struct node* node = (struct node*)malloc(sizeof(struct node));

    if(node != NULL){
        node->data = item;
        node->next = NULL;
        return node;
    }
    else{
        printf("\nHeap Underflow\n");
        exit(EXIT_FAILURE);
    }
}

//delete at the begining
int dequeue(){
    if(front == NULL){
        printf("\nQueue Underflow\n");
        exit(EXIT_FAILURE);
    }
    struct node *temp = front;
    printf("Removing : %d\n", temp->data);

    front = front->next;

    if(front == NULL) rear = NULL;

    int item = temp->data;
    free(temp);
    return item;
}

void enqueue(int item){
    struct node* n_node = newnode(item);
    printf("Inserting : %d\n", item);

    if(front == NULL){
        front = n_node; rear = n_node;
    }

    else{
        rear->next = n_node;
        rear = n_node;
    }
}

int peek(){
    if(front!=NULL) return front->data;
    else exit(EXIT_FAILURE);
}

int isempty(){
    return rear == NULL && front == NULL;
}

int main() 
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	printf("Front element is %d\n", peek());

	dequeue();
	dequeue();
	dequeue();
	dequeue();

	if (isempty())
		printf("Queue is empty\n");
	else
		printf("Queue is not empty\n");

	return 0;
}
