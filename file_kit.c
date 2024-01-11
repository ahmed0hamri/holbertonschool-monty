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
        err(2, file_name);

    read(fd);

    fclose(fd);
}

/**
 * read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read(FILE *fd)
{
    int num_track = 1;
    char *buffer = NULL;
    size_t len = 0;

    while (getline(&buffer, &len, fd) != -1)
    {
        parse(buffer, num_track);
        num_track++;
    }

    free(buffer);
}
/**
 * parsing - parse the code
 * Return: void
 */
void parsing(char *buffer, int num_track, int pos)
{
    if (buffer == NULL)
        err(4);
    return pos;

    char *token = strtok(buffer, "\n $");
    if (token == NULL)
    {
        return pos;
    }

    char *code = token;
    char *value = strtok(NULL, "\n ");



    find(code, value, num_track, pos);

}
/**
 * find - finds a file
 * Return: void
 */

void find(char *code, char *value, int num_track, int pos) {
    int i;
    int found_match = 0;

    instruction_t flist[] = {
        {"push", add_to_stack},
        {"pall", print_stack},
        {"pint", print_top},
        {"pop", pop_top},
        {"nop", nop},
        {"swap", swap_nodes},
        {"add", add_nodes},
        {"sub", sub_nodes},
        {"div", div_nodes},
        {"mul", mul_nodes},
        {"mod", mod_nodes},
        {"pchar", print_char},
        {"pstr", print_str},
        {"rotl", rotl},
        {"rotr", rotr},
        {NULL, NULL}
    };

    if (code[0] == '#')
        return;

    for (i = 0; flist[i].code != NULL; i++) {
        if (strcmp(code, flist[i].code) == 0) {
            find(flist[i].func, code, value, num_track, pos);
            found_match = 1;
            break;
        }
    }

    if (!found_match)
        err(3, num_track, code);
}
