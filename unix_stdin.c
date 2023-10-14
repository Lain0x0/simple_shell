#include "shell.h"

/**
 * main - Entry Point Of Program
 *
 * @execute_command: Exexcute Commands
 *
 * Return: Always 0 (success)
 *
 * Description: Shell Program With C
*/

void execute_command(const char *command) { system(command); }

int main(int argc, char *argv[])
{
	if (argc != 2)

	{

		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);

		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)

	{
		perror("Error opening file");
		return (1);
	}

	char command[MAX_COMMAND_LENGTH];

	while (fgets(command, sizeof(command), file) != NULL)

	{

		size_t len = strlen(command);

		if (len > 0 && command[len - 1] == '\n')

		{
			command[len - 1] = '\0';
		}

		execute_command(command);
	}

	fclose(file);

	return (0);
}

