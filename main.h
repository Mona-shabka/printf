#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
* struct parameters - struction of parameters.
* @unsign: unsigned parameter if found.
* @plus_flag: plus flag if found
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
unsigned int space_flag		: 1;
unsigned int hashtag_flag	: 1;
unsigned int zero_flag		: 1;
unsigned int minus_flag		: 1;

unsigned int width;
unsigned int precision;

unsigned int h_modifier		: 1;
unsigned int l_modifier		: 1;
} params_t;


/**
* struct specifier - structure.
* @specifier: format.
* @func: input function.
*/

typedef struct specifier
{
char *specifier;
int (*func)(va_list, params_t *);
} specifier_t;


int mo_puts(char *string);
int mo_putchar(int character);

int (*get_specifier(char *string))(va_list list, params_t *params);
int get_print_func(char *string, va_list list, params_t *params);
int get_flag(char *string, params_t *params);
int get_modifier(char *string, params_t *params);
char *get_width(char *string, params_t *params, va_list list);
int print_rev(va_list list, params_t *params);

int print_from_to(char *begin, char *end, char *except);
int print_rot13(va_list list, params_t *params);

char *get_precision(char *string, params_t *params, va_list list);

void init_params(params_t *params, va_list list);

int _printf(const char *format, ...);

char *convert(long int number, int base, int flag, params_t *params);
int print_unsigned(va_list list, params_t *params);
int print_address(va_list list, params_t *params);


int _isdigit(int ch);
int _strlen(char *string);
int print_number(char *string, params_t *params);
int print_number_right_shift(char *string, params_t *params);
int print_number_left_shift(char *string, params_t *params);

int print_hex(va_list list, params_t *params);
int print_octal(va_list list, params_t *params);
int print_binary(va_list list, params_t *params);
int print_HEX(va_list list, params_t *params);


int print_S(va_list list, params_t *params);
int print_char(va_list list, params_t *params);
int print_int(va_list list, params_t *params);
int print_string(va_list list, params_t *params);
int print_percent(va_list list, params_t *params);
#endif
