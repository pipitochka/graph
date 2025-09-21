#include "list.h"
#include <stdlib.h>

list* init_list() {
  list* l = malloc(sizeof(list));
  if (l){
    l->head = NULL;
    l->tail = NULL;
  }
  return l;
}

node* init_node(token* token){
  node* n = malloc(sizeof(node));
  if (n){
    n->token = token;
    n->next = NULL;
  }
  return n;
}

int push_back(list* l, token* tok) {
  if (!l || !tok) return 0;
  
  node* newNode = init_node(tok);
  if (!newNode) return 0;
  
  if (l->tail) {
    l->tail->next = newNode; 
    l->tail = newNode;       
  } else {
    l->head = newNode;
    l->tail = newNode;
  }
  return 1;
}

void free_node(node* n) {
  if (!n) return;
  free_node(n->next);
  free(n);
}

void free_list(list* l) {
  free_node(l->head);
  free(l);
}

void free_node_with_token(node* n) {
  if (!n) return;
  free_node(n->next);
  free_token(n->token);
  free(n);
}

void free_list_with_tokens(list* l) {
  free_node_with_token(l->head);
  free(l);
}