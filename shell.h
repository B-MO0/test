#ifndef SHELL_H
#define SHELL_H

/*globals*/
extern char **environ;
#define MAX_LINE 1024
#define MAX_ARGS 64

/* allowed functions header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>

/*Prototypes*/
void display_prompt(void);
void read_command(char **line);
int parse_command(char *line, char **argv);
void execute_command(char** argv);
int run_shell(void);
char *find_command(char *cmd);
void print_env(void);
#endif 
