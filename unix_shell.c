#include "shell.h"

/**
 * main - Entry Point
 *
 * @argc : Argument Counter
 *
 * @argv : Argument Vector
 *
 * @envp : Environment Pointer.
 *
 * Description : This code give us The PID
 *
 * Return: Always 0 (Success)
*/

int main(int argc, char *argv[], char *envp[])
{

	char input[MAX_INPUT_SIZE];

	while (1)

	{

		printf("$");

		if (fgets(input, sizeof(input), stdin) == NULL)

		{
			break;
		}


	}

	return (0);

}

