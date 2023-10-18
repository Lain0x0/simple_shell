#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_COUNT 64
#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 256
#define MAX_TOKENS 64
#define MAX_ALIAS_LENGTH 1024
#define MAX_ALIASES 1024

void run_shell();

#endif
