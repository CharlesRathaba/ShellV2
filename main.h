#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char *argv[]);
char *get_location(char *command);
void print_env();
void cd (char *dir);
void pwd();
void setenv_cmd(char *argv[]);
void unsetenv_cmd(char *argv[]);
extern char **environ;

#endif 
