#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "stack_arr.h"

#define MAX_SIZE  .5E3 //1E9 //1 GIGA

void mywait();

int main() {


  stack stack = NULL;
  size_t i, j;
  int data;

  printf("stack address: %p\n", stack);
  stack = create(MAX_SIZE);
  printf("Stack created with size: %zu\n", memsize(stack));
  printf("stack address: %p\n", stack);
  mywait();

  srand((unsigned)time(NULL));

  for(i = 0; i < MAX_SIZE; i++) {
    data = rand() % 1000;
    push(stack, data);
  }

  printf("%zu entries pushed with a total size of: %zu\n", i,  
        memsize(stack));
  mywait();

  for(j = 0; j < i/2; j++) {
    data = pop(stack);
  }
  printf("%zu entries getted new total stack size of: %zu\n", j,  
        memsize(stack));
  mywait();

  for(j = 0; j < 10; j++) {
    data = pop(stack);
    printf("Pop #%zu value: %d\n", j, data);
  }

  printf("%zu entries getted new total stack size of: %zu\n", j,  
        memsize(stack));
  mywait();

  for(i = 0; i < MAX_SIZE / 1.5; i++) {
    data = rand() % 1000;
    push(stack, data);
  }

  printf("%zu new entries pushed with a total size of: %zu\n", i,  
        memsize(stack));
  mywait();

  printf("stack address: %p\n", stack);
  destroy(stack);
  stack = NULL;
  printf("stack address: %p\n", stack);
  mywait();

  printf("TESTS DONE!\n");
}

void mywait()
{
  char ch;
  printf("Press enter to continue with test.\n");
  while ((ch = getchar()) !='\n' && ch !=' ')
    ;
}
