#include <stdio.h>
#include <stdlib.h>

#include "stack_lnk.h"

struct node_st {
  item data;
  struct node_st *next;
};

typedef struct node_st *node;

struct stack_st {
  node top;
  size_t used;
};

enum err_op {RUN, MSG, KILL};

static void error_s(char *message, enum err_op option)
{
  if (option != RUN) 
    printf("%s\n", message);
  if (option == KILL)
    exit(EXIT_FAILURE);
}

stack create(void)
{
  stack new_stack = malloc(sizeof(struct stack_st));
  if (!new_stack) 
    error_s("Unable to create stack.", KILL);
   
  new_stack->top = NULL;
  new_stack->used = 0;
  return new_stack;
}

size_t memsize(stack s)
{
  return sizeof(struct node_st) * s->used + sizeof(struct stack_st);
}

bool is_empty(stack s)
{
  return s->top == NULL;
}

bool is_full(stack s)
{
  s = NULL; // Dummy statement to avoid unused param warning.
  return false;
}

item *push(stack s, item data)
{
  static item new_data;
  node new_node = malloc(sizeof(struct node_st));

  if (!new_node) {
    error_s("Unable to create new entry", MSG);
    return NULL;
  }

  new_data = data;
  new_node->data = new_data;
  new_node->next = s->top;
  s->top = new_node;
  s->used++;

  return &new_data;
}

item *pop(stack s)
{
  static item data;

  if (is_empty(s)) {
    error_s("Empty stack", MSG);
    return NULL;
  }

  node old_node = s->top;
  data = s->top->data;
  s->top = s->top->next;
  s->used--;
  free(old_node);

  return &data;
}

void destroy_null(stack *s)
{
  while (!is_empty(*s))
    pop(*s);
  stack old_s = *s;
  free(old_s);
  s = NULL;
}

void destroy(stack s)
{
  while (!is_empty(s))
    pop(s);
  free(s);
}
