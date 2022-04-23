#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack* initStack(){
    struct Stack* newStack = malloc(sizeof(struct Stack));
    newStack->top = NULL;
    return newStack;
};

int main(int argc, char *argv[]){

}