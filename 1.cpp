#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int size;
  int top;
  int *s;
};

struct stack *newstack(int capacity)
{
    struct stack *pt = (struct stack *)malloc(sizeof(struct stack));
    pt->size=capacity;
    pt->top = -1;
    pt->s=(int *)malloc(sizeof(int)*capacity);
     return pt;
}
int size(struct stack *pt)
{
    return pt->top+1;
}
int isempty(struct stack *pt)
{
    return pt->top==-1;
}
int isfull(struct stack *pt)
{
    return pt->top==pt->size-1;
}



void push(struct stack *st, int n )
{
    if(isfull(st))
    {
        printf("Stack overflow\n");
      //  exit(Exit_Failure);
    }
    printf("Inserting : %d\n",n);
    st->s[++st->top]=n;
}

int peek(struct stack *st)
{
    if(!isempty(st))
    return st->s[st->top];
   // else
        // exit(Exit_Failure);
}
int pop(struct stack *st)
{
    if(isempty(st))
    {
            printf("Underflow :\nProgram Terminated!\n");
           // exit(Exit_Failure);
    }
    printf("Removing : %d\n",peek(st));
    
    return st->s[st->top--];
    
}
int main()
{
    struct stack *pt = newstack(5);
    
    push(pt, 1);
    push(pt, 3);
    push(pt, 6);
    
    printf("Top element is:%d\n",peek(pt));
    printf("stack size is: %d\n",size(pt));
    
    pop(pt);
    pop(pt);
    pop(pt);
    
    if(isempty(pt))
    printf("stack is Empty\n");
    else 
    printf("Stack is NOT-Empty\n");
    
    return 0;
    
    
}
