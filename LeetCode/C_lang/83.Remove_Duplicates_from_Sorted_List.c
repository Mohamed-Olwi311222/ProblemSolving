#include "problems.h"

typedef struct ListNode 
{
  int val;
  struct ListNode *next;
}ListNode;

ListNode* deleteDuplicates(ListNode* head){
    ListNode *curr = head;
    ListNode *next = NULL;

    if (!head)
    {
        return (NULL);
    }
    next = curr->next;
    while (next != NULL)
    {
        if (curr->val == next->val)
        {
            curr->next = next->next;
            free(next);
            next = curr->next;
        }
        else
        {
            curr = curr->next;
            next = next->next;
        }
        
    }
    return (head);
}
ListNode *createNode(int val)
{
  ListNode *newnode = malloc(sizeof(ListNode));

  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->val = val;
  newnode->next = NULL;
  return (newnode);
}
void append(ListNode **head, int val)
{
  ListNode *newnode = createNode(val), *ptr = *head;

  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = newnode;
}
void printList(ListNode *head)
{
  if (!head)
  {
    return;
  }
  while (head != NULL)
  {
    printf("%d ->", head->val);
    head = head->next;
  }
  printf("\n");
}
int main(void)
{
    ListNode *head = NULL;
    head = createNode(1);
    append(&head, 1);
    append(&head, 2);
    append(&head, 2);
    append(&head, 3);
    printList(head);
    deleteDuplicates(head); 
    printList(head);
}
