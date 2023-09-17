#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
* struct parameters - This is the tructure of parameters.
* @unsign: the unsigned parameter if found.
* @plus_flag: the plus flag if found
* @minus_flag: if found.
* @space_flag: if found.
* @zero_flag: if found.
* @hashtag_flag: if found.
* @width: width if found.
* @precision: if found.
* @h_modifier: if found.
* @l_modifier: if found.
*/

typedef struct parameters
{
unsigned int unsign		: 1;
unsigned int plus_flag		: 1;
unsigned int minus_flag		: 1;
unsigned int space_flag		: 1;
unsigned int zero_flag		: 1;
unsigned int hashtag_flag	: 1;
unsigned int width;
unsigned int precision;
unsigned int h_modifier		: 1;
unsigned int l_modifier		: 1;
} params_t;


/**
* struct specifier - This is the structure specifier
*
* @specifier: format.
* @func: input function.
*/

typedef struct specifier
{
char *specifier;
int (*func)(va_list, params_t *);
} specifier_t;


int _puts(char *string);
int _putchar(int character);

int (*get_specifiers(char *string))(va_list list, params_t *params);
int get_print_func(char *string, va_list list, params_t *params);
int get_flag(char *string, params_t *params);
int get_modifier(char *string, params_t *params);
char *get_width(char *string, params_t *params, va_list list);

int print_rev(va_list list, params_t *params);
int print_from_to(char *begin, char *stop, char *except);
int print_rot13(va_list list, params_t *params);

char *get_precision(char *string, params_t *params, va_list list);

void init_params(params_t *params, va_list list);

int _printf(const char *format, ...);

#endif
