#include "monty.h"
stack_t *head = NULL;
/**
 * c_node.c - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        error(4);
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}
