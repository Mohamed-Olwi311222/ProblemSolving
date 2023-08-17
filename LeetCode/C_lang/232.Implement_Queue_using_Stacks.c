#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


/*-------------------------------------StructsStart---------------------------------------*/
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

typedef struct MyQueue
{
    stack *s1;
    stack *s2;
} MyQueue;
/*-------------------------------------StructsEnd-----------------------------------------*/



/*-------------------------------------StackStart-----------------------------------------*/
node *create_new_node(int data)
{
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->data = data;
  newnode->next = NULL;
  return (newnode);
}

void push(stack **stack, int data)
{
  node *newnode = create_new_node(data);
  if ((*stack)->top == NULL)
  {
    (*stack)->top = newnode;
    return;
  }
  newnode->next = (*stack)->top;
  (*stack)->top = newnode;
}
int pop(stack **stack)
{
    node *top_node;
    int data;

    if (*stack == NULL || (*stack)->top == NULL)
    {
        return INT_MIN;
    }
    top_node = (*stack)->top;
    data = top_node->data;
    (*stack)->top = (*stack)->top->next;
    free(top_node);

    return data;
}
/*----------------------------------StackEnd----------------------------------------------*/



/*----------------------------------QueueStart--------------------------------------------*/
MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));

    q->s1 = malloc(sizeof(stack));
    q->s1->top = NULL;
    q->s2 = malloc(sizeof(stack));
    q->s2->top = NULL;
    if (q == NULL || q->s1 == NULL || q->s2 == NULL)
    {
        return NULL;
    }
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
  push(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
  int res = 0;
  stack *s1 = obj->s1;
  stack *s2 = obj->s2;

  if (s2->top != NULL) {
    res = pop(&s2);
  } else {
    while (s1->top != NULL) {
      push(&s2, pop(&s1));
    }
    res = pop(&s2);
  }

  return res;
}

int myQueuePeek(MyQueue* obj) {
    node *s1_top = obj->s1->top;
    node *s2_top = obj->s2->top;
    int res = 0;

    if (s2_top != NULL)
    {
        res = s2_top->data;   
    }
    else
    {
        while (s1_top != NULL)
        {
            res = s1_top->data;
            s1_top = s1_top->next;   
        }
    }
    return (res);
}

bool myQueueEmpty(MyQueue* obj) {
  if (obj->s1->top == NULL && obj->s2->top == NULL)
  {
      return (true);
  }
  return (false);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->top); // Free the top node of s1
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
/*---------------------------------QueueEnd-----------------------------------------------*/

int main(void)
{
    int x, param_2;
    MyQueue* obj = myQueueCreate();

    x = 1;
    myQueuePush(obj, x);
    x = 2;
    myQueuePush(obj, x);
    x = 3;
    myQueuePush(obj, x);
    x = 4;
    myQueuePush(obj, x);
    param_2 = myQueuePop(obj);
    x = 5;
    myQueuePush(obj, x);

    param_2 = myQueuePop(obj);
    param_2 = myQueuePop(obj);
    param_2 = myQueuePop(obj);
    param_2 = myQueuePop(obj);
    
    bool param_4 = myQueueEmpty(obj);
 
    myQueueFree(obj);
}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
