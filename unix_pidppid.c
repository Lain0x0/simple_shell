#include "shell.h"

char* replace_variables(char* command, int last_exit_status)
{
	char* pid = malloc(sizeof(char) * 10);

	sprintf(pid, "%d", getpid());

	char* replaced_command = malloc(sizeof(char) * strlen(command) * 2);

	int replaced_index = 0;

	for (int i = 0; i < strlen(command); i++)

	{
		if (command[i] == '$' && command[i+1] == '$')

		{
			strcat(replaced_command, pid);

			replaced_index += strlen(pid);

			i++;

		}

		else if (command[i] == '$' && command[i+1] == '?')

		{
			char exit_status[10];

			sprintf(exit_status, "%d", last_exit_status);

			strcat(replaced_command, exit_status);

			replaced_index += strlen(exit_status);

			i++;

		}

		else

		{
			replaced_command[replaced_index] = command[i];

			replaced_index++;
		}
	}

	replaced_command[replaced_index] = '\0';

	free(pid);

	return replaced_command;
}

int main(void)
{
	int last_exit_status = 0;


	while (1)

	{
		char* command = malloc(sizeof(char) * 100);

		printf("%s@ubuntu:~/shell$ ", getenv("USER"));

		fgets(command, 100, stdin);

		command[strcspn(command, "\n")] = '\0';


		if (strcmp(command, "exit") == 0)

		{
			exit(0);
		}

		command = replace_variables(command, last_exit_status);

		char* args[100];

		char* token = strtok(command, " ");

		int arg_index = 0;

		while (token != NULL)

		{
			args[arg_index] = token;

			arg_index++;

			token = strtok(NULL, " ");
		}

		args[arg_index] = NULL;

		int pid = fork();

		if (pid == 0)

		{
			execvp(args[0], args);

			exit(1);

		}

		else if (pid > 0)

		{
			wait(&last_exit_status);

		}

		else

		{
			last_exit_status = 1;

			printf("Error: Fork failed\n");
		}

		free(command);
	}

	return (0);
}

