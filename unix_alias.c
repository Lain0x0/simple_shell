#include "shell.h"

/**
 * main - The main function for the alias management program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * @printAliases : Print all defined aliases.
 * @setAlias : Set or update aliases.
 * @struct : Structure to store an alias.
 * @print_aliases :  Function to print aliases
 * @set_alias : Function to set an alias
 * @alias_builtin : Function to handle alias built-in command.
 * Return: 0 on success.
 */

typedef struct
{
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];
}
Alias;

Alias aliases[100];
int numAliases = 0;

void print_aliases(char **args, int numArgs)
{
	if (numArgs == 0)

	{

		for (int i = 0; i < numAliases; i++)

		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	}

	else

	{
		for (int i = 0; i < numArgs; i++)

		{
			char *name = args[i];

			int found = 0;

			for (int j = 0; j < numAliases; j++)

			{
				if (strcmp(name, aliases[j].name) == 0)

				{
					printf("%s='%s'\n", aliases[j].name, aliases[j].value);

					found = 1;

					break;
				}
			}

			if (!found)

			{
				printf("Alias not found: %s\n", name);
			}
		}
	}
}

void set_alias(char **args, int numArgs)
{
	for (int i = 0; i < numArgs; i++)

	{
		char *arg = args[i];

		char *equals = strchr(arg, '=');

		if (equals != NULL)

		{
			int nameLength = equals - arg;

			char name[MAX_ALIAS_LENGTH];

			strncpy(name, arg, nameLength);

			name[nameLength] = '\0';

			char *value = equals + 1;

			int found = 0;

			for (int j = 0; j < numAliases; j++)

			{
				if (strcmp(name, aliases[j].name) == 0)

				{

					strncpy(aliases[j].value, value, MAX_ALIAS_LENGTH);

					found = 1;

					break;
				}
			}

			if (!found)

			{
				if (numAliases >= 100)

				{

					printf("Maximum number of aliases reached\n");
					return;
				}

				strcpy(aliases[numAliases].name, name);

				strcpy(aliases[numAliases].value, value);

				numAliases++;
			}
		}

		else

		{
			printf("Invalid alias format: %s\n", arg);
		}
	}
}

void alias_builtin(char **args, int numArgs)
{
	if (numArgs == 0)

	{
		char *aliasNames[numAliases];

		for (int i = 0; i < numAliases; i++)

		{
			aliasNames[i] = aliases[i].name;
		}

		print_aliases(aliasNames, numAliases);

	}

	else

	{
		if (strcmp(args[0], "-h") == 0 || strcmp(args[0], "--help") == 0)

		{
			printf("Usage: alias [name[='value'] ...]\n");

			printf("alias: Prints a list of all aliases, one per line, in the form " "name='value'\n");
			printf("alias name [name2 ...]: Prints the aliases name, name2, etc 1 "
					"per line, in the form name='value'\n");
			printf("alias name='value' [...]: Defines an alias for each name whose "
					"value is given. If name is already an alias, replaces its value "
					"with value\n");
		}

		else

		{
			set_alias(args, numArgs);
		}
	}
}

int main(void)
{
	while (1)

	{
		char user_input[MAX_ALIAS_LENGTH];

		printf("$ ");

		fgets(user_input, sizeof(user_input), stdin);

		user_input[strcspn(user_input, "\n")] = '\0';

		char *token = strtok(user_input, " ");

		char *args[100];

		int numArgs = 0;

		while (token != NULL)

		{
			args[numArgs] = token;

			numArgs++;

			token = strtok(NULL, " ");
		}

		if (numArgs == 0)

		{
			continue;
		}

		if (strcmp(args[0], "alias") == 0)

		{
			alias_builtin(args + 1, numArgs - 1);
		}
	}
	return (0);
}
