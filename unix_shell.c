#include "shell.h"

/**
 * main - Entry Point
 *
 * Description : This code give us The PID
 *
 * Return: Always 0 (Success)
*/

int main(void)
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

