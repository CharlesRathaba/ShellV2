#include "main.h"

/**
 * cd - change directory
 * @dir: directory to change to
 *
 * Return: void
*/

void cd(char *dir)
{
	if (chdir(dir) != 0)
	{
		printf("cd: %s: No such file or directory\n", dir);
	}
}

/**
 * pwd - prints the current working directory.
 *
 * Return: void
*/

void pwd(void)
{
	char *dir = getcwd(NULL, 0);

	printf("%s\n", dir);
	free(dir);
}
