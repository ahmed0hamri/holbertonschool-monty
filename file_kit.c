#include "monty.h"

/**
 * oppening - opens a file and does something
 * @file_name: the file name path
 * Return: void
 */
void oppening(char *file_name)
{

    FILE *fd = fopen(file_name, "r");

    if (file_name == NULL || fd == NULL)
        error(2, file_name);
    readit(fd);

    fclose(fd);
}

/**
 * read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readit(FILE *fd)
{
    int num_track = 1;
    char *buffer = NULL;
    size_t len = 0;

    while (getline(&buffer, &len, fd) != -1)
    {
        parsing(buffer, num_track);
        num_track++;
    }

    free(buffer);
}
/**
 * parsing - parse the code
 * Return: void
 */
int parsing(char *buffer, int num_track)
{
    if (buffer == NULL)
        error(4);

    char *token = strtok(buffer, "\n $");
    if (token == NULL)
    {
        return num_track;
    }

    char *value = strtok(NULL, "\n ");

    finding(token, value, num_track);
    return num_track;
}
/**
 * find - finds a file
 * Return: void
 */

void finding(char *code, char *value, int num_track)
{
    int i;
    int found_match = 0;

    instruction_t flist[] = {
        {"push", push},
        {"pall", pal},
        {NULL, NULL}};

    if (code[0] == '#')
        return;

    for (i = 0; flist[i].opcode != NULL; i++)
    {
        if (strcmp(code, flist[i].opcode) == 0)
        {
            calling(flist[i].f, code, value, num_track);
            found_match = 1;
            break;
        }
    }

    if (!found_match)
        error(3, num_track, code);
}
/**
 * calling - Calls the appropriate operation function.
 * Return: void
 */
void calling(op_func func, char *op, char *val, int ln)
{
    stack_t *node;
    int flag;
    int i;

    flag = 1;
    if (strcmp(op, "push") == 0)
    {
        if (val != NULL && val[0] == '-')
        {
            val = val + 1;
            flag = -1;
        }
        if (val == NULL)
            error(5, ln);
        for (i = 0; val[i] != '\0'; i++)
        {
            if (isdigit(val[i]) == 0)
                error(5, ln);
        }
        node = create_node(atoi(val) * flag);
        func(&node, ln);
    }
    else
        func(&head, ln);
}
