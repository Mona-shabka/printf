#include "main.h"

/**
* get_precision - function that find precision from given string.
* @string: input string.
* @params: struction of parameters.
* @list: pointerr of arguments.
* Return: pointer.
*/

char *get_precision(char *string, params_t *params, va_list list)
{
int y = 0;
if (*string != '.')
return (string);
string++;
if (*string == '*')
{
y = va_arg(list, int);
string++;
}
else
{
while (_isdigit(*string))
y = y * 10 + (*string++ - '0');
}
params->precision = y;
return (string);
}
