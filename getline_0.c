#include "shell.h"

/**
 * main - Entry point of shell program
 *
 * parse_command : Parses the user's command
 * and performs the appropriate actions
 * 
 * parse_command - Parses the user's command
 * and performs the appropriate actions
 *
 * @input : The user's input string.
 * @cmd_args : An array to store command arguments.
 * @num_args : The number of arguments in the cmd_args array.
 *
 * Return : Always 0 (success)
 *
*/

void parse_command(char *input, char **cmd_args, int *num_args)

{
	char *token = input;
	*num_args = 0;

	while (*input != '\0' && *num_args < MAX_INPUT_SIZE)

	{
		if (*input == ' ')

		{
			*input = '\0';
			cmd_args[(*num_args)++] = token;
			token = input + 1;
		}

		input++;
	}

	if (token != input)

	{
		cmd_args[(*num_args)++] = token;
	}

	cmd_args[*num_args] = NULL;
}

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *cmd_args[MAX_INPUT_SIZE];
	int num_args;

	while (1)

	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)

		{
			continue;
		}

		parse_command(input, cmd_args, &num_args);

		if (strcmp(cmd_args[0], "exit") == 0)

		{
			break;
		}

		pid_t pid;

		char buffer[MAX_BUFFER_SIZE];

		pid = fork();

		if (pid == 0)

		{
			if (execvp(cmd_args[0], cmd_args) == -1)

			{
				perror("SimpleShell");
			}

			exit(1);
		}

		else if (pid < 0)

		{

			perror("SimpleShell");
		}

		else

		{
			int status;

			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
