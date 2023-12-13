#include "problems.h"
typedef struct list
{
    char val;
    struct list *next;
}node;
typedef struct stack_t
{
    int len;
    node *top;
} stack_t;

node *create_new_node(char val)
{
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL)
    {
        return (NULL);
    }
    newnode->val = val;
    newnode->next = NULL;
    return (newnode);
}

void push(stack_t *stack, char val)
{
    node *newnode = create_new_node(val);

    if (stack->top == NULL)
    {
	stack->len++;
        stack->top = newnode;
        return;
    }
    newnode->next = stack->top;
    stack->top = newnode;
    stack->len++;
}

char pop(stack_t *stack)
{
    node *top_node = stack->top;
    char data;

    if (stack->top == NULL || stack->top->val == NULL)
    {
        return (NULL);
    }
    data = top_node->val;
    stack->top = top_node->next;
    free(top_node);
    stack->len--;
    return(data);
}

char peek(stack_t *stack)
{
    char data;

    if (stack == NULL || stack->top == NULL)
    {
        return(NULL);
    }
    data = stack->top->val;
    return(data);
}

void free_stack(stack_t *stack)
{
    int i;
    for (i = 0; i < stack->len; i++)
    {
        pop(stack);
    }
}

bool check(stack_t stack, char s)
{
    char closed[3] = {'}', ')', ']'};
    char opened[3] = {'{', '(', '['};
    int i;

    for (i = 0; i < 3; i++)
    {
        if (closed[i] == s && opened[i] == peek(&stack))
        {
            return(true);
        }
    }
    return(false);
}

bool isValid(char* s) {
    stack_t stack;
    int len = strlen(s);
    int i;
    stack.len = 0;
    stack.top = NULL;
    push(&stack, s[0]);
    for (i = 1; i < len; i++)
    {
        if (check(stack, s[i]))
        {
            pop(&stack);
            
        }
	else
	{
		push(&stack, s[i]);
	}
    }
    if (stack.len == 0)
	    return(true);
    free_stack(&stack);
    return(false);
}
int main(void) {
    char *s = "{[]}"; 
    printf("%d\n", isValid(s));
    return 0;
}
