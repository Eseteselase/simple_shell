#ifndef HEADER_FILE
#define HEADER_FILE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/wait.h>

void print_fun(const char *input);
void display_prompt_fun(void);
void input_fun(char **input, size_t *length);
char **tokenize_input(char *input);
void trim_newline(char *str);
char *find_command_path(const char *command);
void execute_fun(char *input);

#endif
