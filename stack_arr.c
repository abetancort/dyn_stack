#include <stdlib.h>
#include <stdio.h>

#include "stack_arr.h"

struct stack_st {
  item *entry;
  size_t top;
  size_t size;
};

enum err_opt {MSG, HALT};

static void error_s(char *message, enum err_opt option)
{
  printf("%s\n", message);
  if (option== HALT)
    exit(EXIT_FAILURE);
}

stack create(size_t size)
{
  stack new_s = malloc(sizeof(struct stack_st));
  item *new_e = malloc(sizeof(item) * size);

  if (new_s == NULL || new_e == NULL)
    error_s("Unable to create stack.", HALT);

  new_s->entry = new_e;
  new_s->top = 0;
  new_s->size = size;

  return new_s;
}

size_t memsize(stack s)
{
  return sizeof(struct stack_st) + sizeof(item) * s->size;
}

bool is_empty(stack s)
{
  return s->top == 0;
}

bool is_full(stack s)
{
  if (s->top == s->size) {
    
    size_t new_size = s->size * 1.05;
    printf("Increasing size of stack by %zu items\n", new_size - s->size);
    
    item *new_e = realloc(s->entry, sizeof(item) * new_size);
    
    if (!new_e) {
      error_s("Unable to increase size of stack dinamically - stack full\n",
              HALT);
      return true;
    }
    s->entry =new_e;
    s->size = new_size;
  }
  return false;
}

static void make_empty(stack s)
{
  s->top = 0;
}

void push(stack s, item data)
{
  if (is_full(s)) {
    error_s("Stack is full unable to push new item", MSG);
    return;
  }

  s->entry[s->top++] = data;
}

item pop(stack s)
{
  if (is_empty(s)) 
    error_s("Stack empty.", HALT);

  return s->entry[--s->top];
}

void destroy (stack s)
{
  make_empty(s);
  free(s->entry);
  free(s);
}
