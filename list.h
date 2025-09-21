#ifndef LIST_H
#define LIST_H
#include "token.h"

typedef struct node {
  struct node *next;
  token* token;
} node;

typedef struct list {
  node *head;
  node *tail;
} list;

list* init_list();

void push_back(list* l, token* tok);

void free_list(list* l);

#endif //LIST_H
