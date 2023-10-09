#include "shell.h"

/**
 * main - Entry Point
 * Description: This program prints the process ID (PID).
 * Return: Always 0 (Success)
 */
int main(void)
{

	int pid;

	pid = getpid();

	printf("The Process ID is: %d\n", pid);

	return (0);
}

