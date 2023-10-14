#include "shell.h"

/**
 * main - Entry Point of The Program
 *
 * Return: 0 on success
*/


int main(void)
{
	char command[1000];

	while (1)

	{
		printf("user@~$ ");

		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		char *cmd;

		char *token = strtok(command, ";");

		while (token != NULL)

		{
			cmd = token;

			while (*cmd == ' ')

			{
				cmd++;
			}

			if (*cmd != '\0')

			{
				char output[1000];

				FILE *fp = popen(cmd, "r");

				if (fp == NULL)

				{
					printf("ls: cannot access %s: No such file or directory\n", cmd);

				}

				else

				{
					while (fgets(output, sizeof(output), fp) != NULL)

					{
						printf("%s", output);

					}
					pclose(fp);
				}
			}

			token = strtok(NULL, ";");
		}
	}
	return (0);
}
