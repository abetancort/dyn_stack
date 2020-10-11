#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdbool.h>

typedef long long item;
typedef struct stack_st *stack;

stack create(size_t entries);
size_t memsize(stack s);
bool is_empty(stack s);
bool is_full(stack s);
void push(stack s, item data);
item pop(stack s);
void destroy(stack s);

#endif /* STACK_ARR_H */
