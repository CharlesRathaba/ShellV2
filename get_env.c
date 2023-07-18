#include "main.h"

/**
 * print_env - function that prints the environment
 *
 * Return: void
*/

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * setenv_cmd - function that sets a new environment variable
 * @argv: list of arguments passed to the function
 *
 * Return: void
*/

void setenv_cmd(char *argv[])
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}
	if (setenv(argv[1], argv[2], 1) == -1)
	{
		perror("Error");
	}
}

/**
 * unsetenv_cmd - function that unsets an environment variable
 * @argv: list of arguments passed to the function
 *
 * Return: void
*/

void unsetenv_cmd(char *argv[])
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}
	if (unsetenv(argv[1]) == -1)
	{
		perror("Error");
	}
}
