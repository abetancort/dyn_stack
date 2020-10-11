CC = gcc
CFLAGS = -ggdb3 -Wall -pedantic -ansi -std=c99 -O

all: stack_arr_test stack_lnk_test

stack_arr_test: stack_arr_test.o stack_arr.o
	$(CC) $(CFLAGS) -o stack_arr_test stack_arr_test.o stack_arr.o

stack_arr_test.o: stack_arr_test.c stack_arr.h
	$(CC) $(CFLAGS) -c -ggdb3 stack_arr_test.c

stack_arr.o: stack_arr.c stack_arr.h
	$(CC) $(CFLAGS) -c -ggdb3 stack_arr.c


stack_lnk_test: stack_lnk_test.o stack_lnk.o
	$(CC) $(CFLAGS) -o stack_lnk_test stack_lnk_test.o stack_lnk.o

stack_lnk_test.o: stack_lnk_test.c stack_lnk.h
	$(CC) $(CFLAGS) -c stack_lnk_test.c

stack_lnk.o: stack_lnk.c stack_lnk.h
	$(CC) $(CFLAGS) -c stack_lnk.c

