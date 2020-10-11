#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "stack_lnk.h"

#define MAX_SIZE 100000

void mywait();

int main()
{

  stack stack = NULL;
  size_t i, j;
  int data;
  int *datap = NULL;

  printf("stack address: %p\n", stack);
  stack = create();
  printf("Stack created with size: %zu\n", memsize(stack));
  printf("stack address: %p\n", stack);
  mywait();

  srand((unsigned)time(NULL));

  for(i = 0; i < MAX_SIZE; i++) {
    data = rand() % 1000;
    datap = push(stack, data);
    if (datap == NULL)
      printf("NULL entry!\n");
  }

  printf("%zu entries pushed with a total size of: %zu\n", i,  
        memsize(stack));
  mywait();

  for(j = 0; j < i/2; j++) {
    datap = pop(stack);
    if (datap == NULL)
      printf("NULL entry!\n");
  }
  printf("%zu entries getted new total stack size of: %zu\n", j,  
        memsize(stack));
  mywait();

  for(j = 0; j < 10; j++) {
    datap = pop(stack);
    if (datap == NULL)
      printf("NULL entry!\n");
    else
      printf("Pop #%zu value: %d\n", j, *datap);
  }

  printf("%zu entries getted new total stack size of: %zu\n", j,  
        memsize(stack));
  mywait();

  printf("stack address: %p\n", stack);
  //destroy(stack);
  destroy_null(&stack);
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
