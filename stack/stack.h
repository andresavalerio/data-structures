#ifndef STACK_H_
#define STACK_H_

struct item{
  char val;
};

struct node{
  struct node* next;
  struct node* prev;
  struct item* item;
};

struct stack{
  struct node* top;
  int size;
};

struct node* createNode(struct item* i);

struct stack* createStack();

struct item* getTop(struct stack* s);

void pop(struct stack* s);

void push(struct stack* s, struct node* n);

int getSize(struct stack* s);

void display(struct stack* s);

#endif
