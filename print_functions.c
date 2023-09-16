#include "main.h"

/**
* print_S - a function that show specified format.
* @list: pointerr of arguments
* @params: structure.
* Return: integer.
*/

int print_S(va_list list, params_t *params)
{
int sum = 0;
char *hexa;
char *string = va_arg(list, char *);

if ((int)(!string))
return (_puts(NULL_STRING));
for (; *string; string++)
{
if ((*string > 0 && *string < 32) || *string >= 127)
{
sum += _putchar('\\');
sum += _putchar('x');
hexa = convert(*string, 16, 0, params);
if (!hexa[1])
sum += _putchar('0');
sum += _puts(hexa);
}
else
{
sum += _putchar(*string);
}
}
return (sum);
}

/**
* print_char - a function that print letters.
* @list: pointerr of arguments
* @params: structure.
* Return: sum.
*/

int print_char(va_list list, params_t *params)
{
unsigned int c = va_arg(list, int), pad1 = 1, sum = 0;
char pad = ' ';

if (params->minus_flag)
sum += _putchar(c);
while (pad1++ < params->width)
sum += _putchar(pad);
if (!params->minus_flag)
sum += _putchar(c);
return (sum);
}

/**
* print_int - a function that print numbers.
* @list: pointerr of arguments
* @params: structure.
* Return: number.
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
* print_string - a function that print string.
* @list: pointerr of arguments
* @params: structure.
* Return: sum.
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
sum += _putchar(*string++);
else
sum += _puts(string);
}
while (y++ < params->width)
sum += _putchar(pad);
if (!params->minus_flag)
{
if (params->precision != UINT_MAX)
for (x = 0; x < pad1; x++)
sum += _putchar(*string++);
else
sum += _puts(string);
}
return (sum);
}

/**
* print_percent - a function that print letters.
* @list: pointerr of arguments
* @params: structure.
* Return: integer.
*/

int print_percent(va_list list, params_t *params)
{
(void)params;
(void)list;
return (_putchar('%'));
}
