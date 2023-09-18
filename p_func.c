#include "main.h"

/**
* print_S - This function shows a specified format
* @list: pointerr of arguments
* @params: structure
*
* Return: sum
*/

int print_S(va_list list, params_t *params)
{
int sum = 0;
char *hexa;
char *string = va_arg(list, char *);

if ((int)(!string))
return (mo_puts(NULL_STRING));
for (; *string; string++)
{
if ((*string > 0 && *string < 32) || *string >= 127)
{
sum += mo_putchar('\\');
sum += mo_putchar('x');
hexa = convert(*string, 16, 0, params);
if (!hexa[1])
sum += mo_putchar('0');
sum += mo_puts(hexa);
}
else
{
sum += mo_putchar(*string);
}
}
return (sum);
}

/**
* print_char -  This function prints letters
* @list: pointerr of arguments
* @params: structure
*
* Return: sum
*/

int print_char(va_list list, params_t *params)
{
unsigned int c = va_arg(list, int), pad1 = 1, sum = 0;
char pad = ' ';

if (params->minus_flag)
sum += mo_putchar(c);
while (pad1++ < params->width)
sum += mo_putchar(pad);
if (!params->minus_flag)
sum += mo_putchar(c);
return (sum);
}

/**
* print_int - This function print numbers
* @list: pointerr of arguments
* @params: structure
*
* Return: number
*/

int print_int(va_list list, params_t *params)
{
long m;

if (params->l_modifier)
m = va_arg(list, long);
else if (params->h_modifier)
m = (short int)va_arg(list, int);
else
m = (int)va_arg(list, int);
return (print_number(convert(m, 10, 0, params), params));
}

/**
* print_string - This function print a string
* @list: pointerr of arguments
* @params: structure
*
* Return: sum
*/

int print_string(va_list list, params_t *params)
{
unsigned int pad1 = 0, sum = 0, x = 0, y;
char pad = ' ', *string = va_arg(list, char *);

(void)params;

switch ((int)(!string))
case 1:
string = NULL_STRING;

y = pad1 = _strlen(string);
if (params->precision < pad1)
y = pad1 = params->precision;
if (params->minus_flag)
{
if (params->precision != UINT_MAX)
for (x = 0; x < pad1; x++)
sum += mo_putchar(*string++);
else
sum += mo_puts(string);
}
while (y++ < params->width)
sum += mo_putchar(pad);
if (!params->minus_flag)
{
if (params->precision != UINT_MAX)
for (x = 0; x < pad1; x++)
sum += mo_putchar(*string++);
else
sum += mo_puts(string);
}
return (sum);
}

/**
* print_percent - This function prints letters
* @list: pointerr of arguments
* @params: structure
*
* Return: integer
*/

int print_percent(va_list list, params_t *params)
{
(void)params;
(void)list;
return (mo_putchar('%'));
}
