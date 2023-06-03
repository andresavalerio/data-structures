#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
input: string com parenteses e outros caracteres
()(())())()
output: dizer se ta balanceado ou não
 */

int main(){
  struct item item1;
  struct node* node1;
  struct stack* stack1;
  int stackSize;
  char input[10];

  scanf("%s", input);

  stack1 = createStack();
  display(stack1);

  for(int i = 0; input[i] != '\0';i++){
    if(input[i] == '('){
      item1.val = '(';
      node1 = createNode(&item1);
      push(stack1, node1);
    }
    else if(input[i] == ')'){
      if(getSize(stack1) == 0){
        perror("String desbalanceada");
        break;
      }
      pop(stack1);
    }
  }

  stackSize = getSize(stack1);
  if (stackSize != 0){
    perror("String desbalanceada");
  }
  else {
    printf("String balanceada\n");
  }
  printf("Stack size: %d\n", stackSize);

  return 0;
}
