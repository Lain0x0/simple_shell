#include "shell.h"

/**
 * execute_command - Execute a command in a child process
 *
 * @args : An array of strings containing the command
 *
 * Description : Shell by using C #2
*/

void execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
	char *token;
	int arg_count;

	while (1)
	{
		printf("$ ");
		fgets(input, MAX_INPUT_LENGTH, stdin);

		input[strcspn(input, "\n")] = '\0';

		token = strtok(input, " ");
		arg_count = 0;

		while (token != NULL)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}

		args[arg_count] = NULL;

		if (arg_count > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit(0);
			}
			execute_command(args);
		}
	}

	return 0;
}
