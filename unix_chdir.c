#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * @new_dir: The new directory path
 *
 * update_pwd - Update the PWD environment variable
 *
 * Return : Always 0 (SUCCESS)
 *
 * Description : Shell program with C
 *
*/









void update_pwd(char *new_dir)
{
	if (setenv("PWD", new_dir, 1) == -1)

	{
		perror("setenv");
	}
}

int main(void)
{
	char input[PATH_MAX];

	char *home = getenv("HOME");

	char *current_dir;

	while (1)

	{
		current_dir = getcwd(NULL, 0);

		if (current_dir == NULL)

		{
			perror("getcwd");
			return (1);
		}

		printf("$ %s$ ", current_dir);

		free(current_dir);

		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "cd") == 0 || strcmp(input, "cd ") == 0)

		{
			if (chdir(home) == -1)

			{
				perror("chdir");
			}

			update_pwd(home);

		}

		else if (strncmp(input, "cd ", 3) == 0)

		{
			char *dir = input + 3;

			if (chdir(dir) == -1)

			{
				perror("chdir");
			}

			update_pwd(dir);

		}

		else if (strcmp(input, "cd -") == 0)

		{
			char *prev_dir = getenv("OLDPWD");

			if (prev_dir == NULL)

			{
				printf("OLDPWD not set\n");

			}

			else

			{
				if (chdir(prev_dir) == -1)

				{
					perror("chdir");
				}

				update_pwd(prev_dir);
			}

		}

		else

		{
			printf("Command not recognized: %s\n", input);
		}
	}

	return (0);
}

