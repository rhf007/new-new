#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

int _putchar(char c);
void _puts(char *str);
void init_zero(unsigned int *array, size_t size);
char *which(char *cmd);
void execute(char **argv);
char *our_get_line();
#endif /*ifndef MAIN_H*/
