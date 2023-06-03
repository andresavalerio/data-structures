#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node* createNode(struct item* i){
  struct node* n = malloc(sizeof(struct node));

  n->item = i;

  n->next = NULL;
  n->prev = NULL;

  return n;
}

struct stack* createStack(){
  struct stack* s = malloc(sizeof(struct stack));

  s->top = NULL;
  s->size = 0;

  return s;
}

struct item* getTop(struct stack* s){
  return (s->top != NULL) ? s->top->item : NULL;
}

void pop(struct stack* s){
  if (s->top != NULL){
    if(s->top->prev != NULL) s->top->prev->next = NULL;
    struct node* aux = s->top;
    s->top = s->top->prev;
    s->size--;

    free(aux);

  }

}

void push(struct stack* s, struct node* n){
  if(s->top != NULL){
    n->prev = s->top;

    s->top->next = n;
  }
  s->top = n;
  s->size++;
}

int getSize(struct stack* s){
  return s->size;
}

void display(struct stack* s){
  if (s->top == NULL){
    perror("Pilha vazia");
    return;
  }
  struct node* aux = s->top;

  printf("START DISPLAY\n");

  while(aux != NULL){
    printf("%p<-[%p]->%p\n", aux->prev, aux, aux->next);

    aux = aux->prev;
  }

  printf("END DISPLAY\n");
}
