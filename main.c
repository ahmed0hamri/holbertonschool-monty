#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		error(1);
	}
	oppening(argv[1]);
	exit(EXIT_SUCCESS);
}
