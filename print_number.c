#include "main.h"

/**
* _isdigit - a function that show if letter is number.
* @ch: checked letter.
* Return: 1 (number) and 0 (letter).
*/

int _isdigit(int ch)
{
return (ch >= '0' && ch <= '9');
}

/**
* _strlen - a function that give the length of string.
* @string: input string.
* Return: length.
*/

int _strlen(char *string)
{
int length = 0;

while (*string++)
length++;
return (length);
}

/**
* print_number - a function that print integers.
* @string: input string.
* @params: the structure
* Return: number.
*/

int print_number(char *string, params_t *params)
{
int negative = (!params->unsign && *string == '-');
unsigned int length = _strlen(string);

if (!params->precision && *string == '0' && !string[1])
string = "";
if (negative)
{
string++;
length--;
}
if (params->precision != UINT_MAX)
while (length++ < params->precision)
*--string = '0';
if (negative)
*--string = '-';
if (!params->minus_flag)
return (print_number_right_shift(string, params));
else
return (print_number_left_shift(string, params));
}

/**
* print_number_right_shift - a function that print integers.
* @string: input string.
* @params: the structure
* Return: integers.
*/

int print_number_right_shift(char *string, params_t *params)
{
char pad = ' ';
unsigned int x = 0, negative, negative1, length = _strlen(string);

if (params->zero_flag && !params->minus_flag)
pad = '0';
negative = negative1 = (!params->unsign && *string == '-');
if (negative && length < params->width && pad == '0' && !params->minus_flag)
string++;
else
negative = 0;
if ((params->plus_flag && !negative1) ||
(!params->plus_flag && params->space_flag && !negative1))
length++;
if (negative && pad == '0')
x += mo_putchar('-');
if (params->plus_flag && !negative1 && pad == '0' && !params->unsign)
x +=  mo_putchar('+');
else if (!params->plus_flag && params->space_flag && !negative1 &&
!params->unsign && params->zero_flag)
x += mo_putchar(' ');
while (length++ < params->width)
x += mo_putchar(pad);
if (negative && pad == ' ')
x += mo_putchar('-');
if (params->plus_flag && !negative1 && pad == ' ' && !params->unsign)
x += mo_putchar('+');
else if (!params->plus_flag && params->space_flag && !negative1 &&
!params->unsign && !params->zero_flag)
x += mo_putchar(' ');
x += mo_puts(string);
return (x);
}

/**
* print_number_left_shift - a function that print integers.
* @string: input string.
* @params: the structure
* Return: integers.
*/

int print_number_left_shift(char *string, params_t *params)
{
char pad = ' ';
unsigned int x = 0, negative, negative1, length = _strlen(string);

if (params->zero_flag && !params->minus_flag)
pad = '0';
negative = negative1 = (!params->unsign && *string == '-');
if (negative && length < params->width && pad == '0' && !params->minus_flag)
string++;
else
negative = 0;

if (params->plus_flag && !negative1 && !params->unsign)
x += mo_putchar('+'), length++;
else if (params->space_flag && !negative1 && !params->unsign)
x += mo_putchar(' '), length++;
x += mo_puts(string);
while (length++ < params->width)
x += mo_putchar(pad);
return (x);
}
