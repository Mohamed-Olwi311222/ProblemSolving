#include "problems.h"

 struct ListNode {
      int val;
      struct ListNode *next;
 };
/**
 * list_len - gets the length of the list
 * @head: head of the list
 * Return: the length of the list
*/
size_t list_len(struct ListNode *head)
{
    size_t len = 0;

    if (!head)
    {
        return (len);
    }
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return (len);
}
/**
 * half_list - get the half of the list
 * @head: head of the list
 * @len: len of the list
 * Return: a pointer to the half of the list
*/
struct ListNode *half_list(struct ListNode *head, size_t len)
{
    size_t half = 0;
    struct ListNode *ptr = NULL;

    if (!head)
    {
        return (NULL);
    }
    while (head != NULL)
    {
        if (half == (len / 2) - 1)
        {
            if (len % 2 != 0)
            {
                ptr = head->next->next;
            }
            else
            {
                ptr = head->next;
            }
            head->next = NULL;
        }
        head = head->next;
        half++;
    }
    return (ptr);
}
/**
 * reverseList - reverse a linked list
 * @head: head of the list to reverse
 */
void reverseList(struct ListNode **head)
{
	struct ListNode *prev = NULL;
	struct ListNode *curr = *head;
	struct ListNode *next = NULL;

	if (!head)
		return;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
/**
 * compareList - compare the two list
 * @head: original list
 * @length: length of the list
 * Return: 1 if identical else 0
*/
size_t compareList(struct ListNode *head, size_t length)
{
    struct ListNode *half = half_list(head, length);
    reverseList(&half);
    while (head != NULL && half != NULL)
    {
        if (head->val != half->val)
        {
            return (0);
        }
        head = head->next;
        half = half->next;
    }
    reverseList(&half);
    return (1);
}
/**
 * is_palindrome - checks if the list is a palindrome or not
 * @head: head of the list
 * Return: 1 if palindrome, 0 if not
 */
bool isPalindrome(struct ListNode* head)
{
    size_t length = list_len(head);
    size_t res = compareList(head, length);

    return (res);
}
