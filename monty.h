#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void oppening(char *file_name);
int parsing(char *buffer, int line_number);
void readit(FILE *fd);
int len_chars(FILE *);
void finding(char *code, char *value, int num_track);
void push(stack_t **new_node, __attribute__((unused))unsigned int ln);
void pal(stack_t **stack, unsigned int line_number);
void error(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void calling(op_func func, char *op, char *val, int ln);
stack_t *create_node(int n);
#endif