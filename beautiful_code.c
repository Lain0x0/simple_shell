#include "shell.h"

/**
 * main - Entry Point
 * @argc: Argument Counter
 * @argv: Argument Vector
 * @envp: Environment variables
 *
 * Description: This program prints the process ID (PID).
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;

	int pid_t;

	pid_t = getpid();

	printf("The Process ID is: %d\n", pid_t);

	return (0);
}

