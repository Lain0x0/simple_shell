#include "shell.h"

/**
 * main - Entry Point for shell program
 *
 * tokenize : Tokenize a string into words
 *
 * Return : Alwyas 0 (success)
 *
 * Description : Shell Program with C
 *
 * @input : let user to enter command
 *
 * @tokens: An array to store the resulting tokens
 *
*/





void tokenize(char *input, char *tokens[MAX_TOKENS])
{
	int token_count = 0;
	char *token = strtok(input, " \t\n");

	while (token != NULL)

	{
		tokens[token_count] = token;
		token_count++;

		if (token_count >= MAX_TOKENS)

		{
			printf("Too many arguments.\n");
			exit(1);
		}

		token = strtok(NULL, " \t\n");
	}

	tokens[token_count] = NULL;
}

int main(void)

{
	char input[MAX_INPUT_SIZE];
	char *tokens[MAX_TOKENS];

	while (1)

	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			printf("Error reading input.\n");
			exit(1);
		}

		if (input[strlen(input) - 1] == '\n')

		{
			input[strlen(input) - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)

		{
			break;
		}

		tokenize(input, tokens);

		if (tokens[0] != NULL)

		{
			pid_t pid = fork();

			if (pid == 0)

			{
				if (execvp(tokens[0], tokens) == -1)

				{
					printf("Command not found: %s\n", tokens[0]);
					exit(1);
				}
			}

			else if (pid < 0)

			{
				printf("Fork failed.\n");
				exit(1);
			}

			else

			{

				int status;

				waitpid(pid, &status, 0);
			}
		}
	}

	return (0);
}

