#include "shell.h"

/**
 * main - Entry Point of shell Program
 *
 * Return: 0 on success
 *
 * @input: user input
 *
 * @env: Environment Variable
 *
 * Description: Shell Program with C
 *
*/

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	char *env[] = { NULL };
	int status;
	char *custom_vars[2] = {
		"$USER=julien",
		NULL
	};

	int i;
	int j;
	int pid;
	char *token;

	while (1)
	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = 0;

		for (i = 0; custom_vars[i] != NULL; i++)
		{
			if (strstr(input, custom_vars[i]) != NULL)
			{
				char *var_name = strtok(custom_vars[i], "=");
				char *var_value = strtok(NULL, "=");
				char *replacement = malloc(strlen(var_name) + 2);
				sprintf(replacement, "$%s", var_name);

				while (strstr(input, replacement) != NULL)
				{
					char *var_replaced = malloc(strlen(var_value) + strlen(input) - strlen(replacement) + 1);
					char *rest = strstr(input, replacement) + strlen(replacement);
					strncpy(var_replaced, input, strlen(input) - strlen(rest));
					strcat(var_replaced, var_value);
					strcat(var_replaced, rest);
					strcpy(input, var_replaced);
					free(var_replaced);
				}

				free(replacement);
			}
		}

		token = strtok(input, " ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		args[i] = NULL;

		if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				if (strcmp(args[j], "$?") == 0)
				{
					printf("Last exit status: %d\n", status);
				}
				else if (strcmp(args[j], "$$") == 0)
				{
					printf("Shell PID: %d\n", getpid());
				}
			}

			pid = fork();

			if (pid == 0)
			{
				if (execve(args[0], args, env) == -1)
				{
					perror("Execution error");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("Fork error");
			}
			else
			{
				wait(&status);
			}
		}
	}

	return (0);
}

