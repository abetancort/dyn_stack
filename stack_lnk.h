#ifndef STACK_LNK_H

#define STACK_LNK_H
#include <stdbool.h>

typedef struct stack_st *stack;
typedef int item;


stack create(void);
size_t memsize(stack s);
item *push(stack s, item data);
bool is_full(stack s);
bool is_empty(stack s);
item *pop(stack s);
void destroy(stack s);
void destroy_null(stack *s);

#endif /* STACK_LINK_H */
