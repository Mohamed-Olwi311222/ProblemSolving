/*-------------------------------------Include files-------------------------------------------------*/
#include "problems.h"
/*-------------------------------------Structs-------------------------------------------------------*/
typedef struct list
{
  char data;
  struct list *next;
} list_t;
typedef struct queue
{
  list_t *first;
  list_t *last;
} queue;
/*-------------------------------------functions prototypes------------------------------------------*/
list_t *create_new_node(char data);
void init_queue(queue *queue);
bool enqueue(queue *q, char data);
char dequeue(queue *q);
char peek(queue *q);
int firstUniqChar(char * s);
/*-------------------------------------End-----------------------------------------------------------*/
size_t length = 0;

list_t *create_new_node(char data)
{
  list_t *newnode = malloc(sizeof(list_t));
  if (newnode == NULL)
  {
    return (NULL);
  }
  length++;
  newnode->data = data;
  newnode->next = NULL;
  return (newnode);
}

void init_queue(queue *queue)
{
  queue->first = NULL;
  queue->last = NULL;
}

bool enqueue(queue *q, char data)
{
  list_t *node;

  if (q == NULL)
    return (false);
  node = create_new_node(data);

  if (q->last != NULL)
  {
    q->last->next = node;
  }
  q->last = node;
  
  if (q->first == NULL)
  {
    q->first = node;
  }
  return (true);
}

char dequeue(queue *q)
{
  list_t *ptr;
  char data;

  if (q == NULL)
    return (-1);

  ptr = q->first;
  data = ptr->data;

  q->first = q->first->next;
  if (q->first == NULL)
    q->last = NULL;
  free(ptr);
  length--;
  return (data);
}

char peek(queue *q)
{
  list_t *ptr;
  char data;

  if (q == NULL)
    return (NULL);

  ptr = q->first;
  data = ptr->data;
  return (data);
}
int firstUniqChar(char * s)
{
    queue q;
    init_queue(&q);
    int charfreq[128] = {0};
    int size = strlen(s);
  
    for (int i = 0; i < size; i++)
    {
        enqueue(&q, s[i]);
        charfreq[(int) s[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (charfreq[(int) peek(&q)] == 1)
        {
            dequeue(&q);
            return (i);
        }
        dequeue(&q);
    }
    
    return (-1);
}
int main(void)
{
    char *s = "loveleetcode";
    int num = 0;

    num = firstUniqChar(s);
    printf("num: %d\n", num);    
}
