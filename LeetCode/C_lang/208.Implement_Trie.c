#include "problems.h"

#define NUM_CHARS 127
typedef struct Trie{
    struct Trie *children[NUM_CHARS];
    bool terminal;
} Trie;


Trie* trieCreate() {
    Trie *newnode = malloc(sizeof(Trie));
	int i;

	if (newnode == NULL)
		return (NULL);

	for (i = 0; i < NUM_CHARS; i++)
		newnode->children[i] = NULL;
	newnode->terminal = false;
	return (newnode);
}

void trieInsert(Trie* obj, char * word) {
  int length = strlen(word), i;
  unsigned char *text_u = word;

  if (obj == NULL)
  {
      obj = trieCreate();
  }
  for (i = 0; i < length; i++)
  {
      if (obj->children[text_u[i]] == NULL)
      {
          obj->children[text_u[i]] = trieCreate();
      }
      obj = obj->children[text_u[i]];
  }

  if (obj->terminal == true)
  {
      return;
  }
  obj->terminal = true;
}

bool trieSearch(Trie* obj, char * word) {
  	int length = strlen(word), i;
	unsigned char *word_u = (unsigned *) word;

	if (!obj)
	{
		return (false);
	}

	for (i = 0; i < length; i++)
	{
		if (obj->children[word_u[i]] == NULL)
		{
			return (false);
		}
		obj = obj->children[word_u[i]];
	}

	if (obj->terminal == false)
	{
		return (false);
	}
		return (true);
}

bool trieStartsWith(Trie* obj, char * prefix) {
  
	int length = strlen(prefix), i;
	unsigned char *prefix_u = (unsigned *) prefix;

	if (!obj || !prefix)
	{
		return (false);
	}
	for (i = 0; i < length; i++)
	{
		if (obj->children[prefix_u[i]] == NULL)
		{
			return (false);
		}
		obj = obj->children[prefix_u[i]];
	}
	return (true);
}

void trieFree(Trie* obj) {
    int i;

    if (obj == NULL)
    {
        return;
    }
    
    for (i = 0; i < NUM_CHARS; ++i) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }
    
    free(obj);
}

