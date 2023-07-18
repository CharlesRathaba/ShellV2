#include "main.h"

/**
 * execmd - executes a command from argv
 * @argv: arguments passed to function
 *
 * Return: void
*/

void execmd(char *argv[])
{
	char *command, *actual_command;

	if (argv && argv[0])
	{
		/* get command */
		command = argv[0];
		if (strcmp(command, "setenv") == 0)
		{
			setenv_cmd(argv);
		}
		if (strcmp(command, "unsetenv") == 0)
		{
			unsetenv_cmd(argv);
		}
		if (strcmp(argv[0], "env") == 0)
		{
			print_env();
		}
		if (strmp(argv[0], "cd") == 0)
		{
			cd(argv[1])
		}
		if (strcmp(argv[0], "pwd") == 0)
		{
			pwd()
		}
		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);
		if (actual_command == NULL)
		{
			printf("Command not found: %s\n", command);
			return;
		}
		/* exercute command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}

