#include "main.h"

/**
* convert - This function converts a number to string.
* @number: input number.
* @base: the base
* @flag: flag of argument.
* @params:structure of parameters.
* Return: string.
*/

char *convert(long int number, int base, int flag, params_t *params)
{
char *pointer;
char sign = 0;
unsigned long x = number;
static char buffer[50];
static char *array;
(void)params;

if (!(flag & CONVERT_UNSIGNED) && number < 0)
{
x = -number;
sign = '-';
}
array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pointer = &buffer[49];
*pointer = '\0';
do {
*--pointer = array[x % base];
x /= base;
} while (x != 0);
if (sign)
*--pointer = sign;
return (pointer);
}

/**
* print_unsigned - function that print unsign number.
* @list: pointer to arguments.
* @params: structure.
* Return: bytes.
*/

int print_unsigned(va_list list, params_t *params)
{
unsigned long m;

if (params->l_modifier)
m = (unsigned long)va_arg(list, unsigned long);
else if (params->h_modifier)
m = (unsigned short int)va_arg(list, unsigned int);
else
m = (unsigned int)va_arg(list, unsigned int);
params->unsign = 1;
return (print_number(convert(m, 10, CONVERT_UNSIGNED, params), params));
}

/**
* print_address - function that print address.
* @list: pointer to arguments.
* @params: structure.
* Return: bytes.
*/

int print_address(va_list list, params_t *params)
{
char *string;
unsigned long int x = va_arg(list, unsigned long int);

if (!x)
return (mo_puts("(nil)"));
string = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--string = 'x';
*--string = '0';
return (print_number(string, params));
}
