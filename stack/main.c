#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  struct item item1, item2;
  struct item* topItem1, *topItem2, *topItem3;
  struct node* node1, *node2;
  struct stack* stack1;

  item1.val = 1;
  item2.val = 2;

  node1 = createNode(&item1);
  node2 = createNode(&item2);

  //printf("%d\n", node1->item->val);

  stack1 = createStack();

  push(stack1, node1);

  printf("TOP: %d\n", stack1->top->item->val);
  printf("TOP: %p<-[%p]->%p\n", stack1->top->prev, stack1->top, stack1->top->next);

  push(stack1, node2);

  printf("NEW TOP: %d\n", stack1->top->item->val);
  printf("NEW TOP: %p<-[%p]->%p\n", stack1->top->prev, stack1->top, stack1->top->next);


  topItem1 = getTop(stack1);
  printf("Top Item 1: %d\n", topItem1->val);

  pop(stack1);
  printf("POP 1: %p<-[%p]->%p\n", stack1->top->prev, stack1->top, stack1->top->next);
  topItem2 = getTop(stack1);
  printf("Top Item 2: %d\n", topItem2->val);


  pop(stack1);
  printf("POP 2: %p<-[%p]->%p\n", stack1->top->prev, stack1->top, stack1->top->next);
  printf("Oi!\n");
  topItem3 = getTop(stack1);
  printf("Outro oi!\n");
  printf("Top Item 3: %d\n", topItem3->val);

  free(node1);
  free(node2);
  free(stack1);

  return 0;
}
