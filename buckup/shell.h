#ifndef HEADER_FILE
#define HEADER_FILE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/wait.h>

extern char **environ;

void print_fun(const char *input);
void display_prompt_fun(void);
void input_fun(char **input, size_t *length);
void custom_itoa(int value, char *str);
void custom_strcat(char *dest, const char *src);
void getenv_fun(char *new_path);

#endif
