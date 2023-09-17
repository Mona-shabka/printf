#include "main.h"

/**
* get_specifiers - This function finds the function format
* @string: input string.
* Return: x
*
*/

int (*get_specifiers(char *string))(va_list list, params_t *params)
{
specifier_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_Hex},
{"p", print_address},
{"S", print_s},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};

int x = 0;

while (specifiers[x].specifier)
{
if (*string == specifiers[x].specifier[0])
{
return (specifiers[x].func);
}
x++;
}

return (NULL);
}

/**
* get_print_func - This function gets the function format
* @string: input string
* @list: pointer of arguments
* @params: the parameters
*
* Return: list params or 0
*
*/

int get_print_func(char *string, va_list list, params_t *params)
{
int (*func)(va_list, params_t *) = get_specifier(string);

if (func)
return (func(list, params));

return (0);
}

/**
* get_flag - This function gets the function flag
* @string: input string.
* @params: struction of parameters.
*
* Return: the flag
*/

int get_flag(char *string, params_t *params)
{

int x = 0;

switch (*string)
{
case '+':
x = params->plus_flag = 1;
break;
case '-':
x = params->minus_flag = 1;
break;
case ' ':
x = params->space_flag = 1;
break;
case '0':
x = params->zero_flag = 1;
break;
case '#':
x = params->hashtag_flag = 1;
break;
}

return (x);
}

/**
* get_modifier - This function gets function modifier
* @string: input string.
* @params: struction of parameters
*
* Return: x
*
*/

int get_modifier(char *string, params_t *params)
{
int x = 0;

switch (*string)
{
case 'l':
x = params->l_modifier = 1;
break;
case 'h':
x = params->h_modifier = 1;
break;
}

return (x);
}

/**
* get_width - This function gets function width.
* @string: input string.
* @params: struction of parameters.
* @list: pointerr of arguments.
*
* Return: string
*
*/

char *get_width(char *string, params_t *params, va_list list)
{

int y = 0;

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
params->width = y;

return (string);
}
