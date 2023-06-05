#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(){
  struct item item;
  struct node* node;
  struct stack* stack;
  bool flag = true;
  int stackSize;
  char input[50];

  scanf("%s", input);

  stack = createStack();
  printf("======== INICIAL STACK ========\n");
  display(stack);
  printf("======== INICIAL STACK ========\n");

  for(int i = 0; input[i] != '\0';i++){
    if(input[i] == '('){
      item.val = '(';
      node = createNode(&item);
      push(stack, node);
    }
    else if(input[i] == ')'){
      if(getSize(stack) == 0){
        flag = false;
        break;
      }
      pop(stack);
    }
  }

  printf("======== FINAL STACK ========\n");
  display(stack);
  printf("======== FINAL STACK ========\n");

  stackSize = getSize(stack);
  if (stackSize != 0 || flag == false){
    perror("String desbalanceada");
  }
  else {
    printf("String balanceada\n");
  }
  printf("Stack size: %d\n", stackSize);

  destroyStack(stack);

  return 0;
}
