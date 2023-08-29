#include "problems.h"

// Define valid pairs of brackets
char opened[] = {'{', '(', '['};
char closed[] = {'}', ')', ']'};

// Define the stack structure
typedef struct stack {
    char bracket;
    struct stack *next;
    struct stack *prev;
} stack_t;

// Function to create a new stack node
stack_t *create_new_node(char brack) {
    stack_t *newnode = malloc(sizeof(stack_t));
    
    if (!newnode) {
        return NULL;
    }
    newnode->bracket = brack;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to push a bracket onto the stack
void push(stack_t **stack, stack_t **bottom, char brack) {
    stack_t *newnode = create_new_node(brack);
    
    if (!newnode) {
        return;
    }
    
    if (!(*stack)) {
        *bottom = newnode;
        *stack = newnode;
    } else {
        (*stack)->prev = newnode;
        newnode->next = *stack;
        *stack = newnode;
    }
}

// Function to pop the top element from the stack
stack_t *pop(stack_t *stack) {
    stack_t *curr = NULL; 

    if (!stack) {
        return (NULL);
    }
    if (stack->next == NULL)
    {
        free(stack);
    }
    else
    {
        curr = stack;
        stack = stack->next;
        free(curr);
    }
    return (stack);
}

// Function to pop the bottom element from the stack
stack_t *pop_bottom(stack_t *bottom, stack_t *stack) {
    stack_t *curr = NULL;

    if (!bottom) {
        return (NULL);
    }

    curr = bottom;
    if (bottom == stack) {
        free(stack);
        stack = NULL;
        bottom = NULL;
    } else {
        bottom = bottom->prev;
        free(curr);
    }
    
    return (bottom);
}

// Function to look up the top element of the stack
int look_up(stack_t *stack)
{
    if (!stack)
    {
        return (-1);
    }
    if (closed[0] == stack->bracket)
    {
        return (0);
    }
    else if (closed[1] == stack->bracket)
    {
        return (1);
    }
    else
    {
        return (2);
    }
}

// Function to check if a character matches the bottom element
int look_bottom(stack_t *bottom) {
    if (!bottom) {
        return (-1);
    }
    if (opened[0] == bottom->bracket)
    {
        return (0);
    }
    else if (opened[1] == bottom->bracket)
    {
        return (1);
    }
    else
    {
        return (2);
    }
}
bool compare_top_and_bottom(stack_t *bottom,stack_t *top)
{
    int b = look_bottom(bottom);
    int t = look_up(top);

    /*Same address then its only one node pushed*/
    if (bottom == top)
    {
        return (false);
    }
    if (b == t && b != -1)
    {
        return (true);
    }
    return (false);
}
// Function to free the entire stack
void free_stack(stack_t **stack) {
    while (pop(*stack));
}

// Function to validate bracket expressions
bool isValid(char *s) {
    stack_t *stack = NULL, *bottom = NULL;
    int len = strlen(s), i;

    // push(&stack, &bottom, s[0]);
    for (i = 0; i < len; i++) {
        push(&stack, &bottom, s[i]);
        if (compare_top_and_bottom(bottom, stack))
        {
           stack = pop_bottom(bottom, stack);
           bottom = pop(stack);
        }
    }
    
    if (stack != NULL) {
        free_stack(&stack);
        return false;
    } else {
        return true;
    }
}

int main(void) {
    char *s = "()"; 
    printf("%d\n", isValid(s));
    return 0;
}
