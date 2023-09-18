#include "main.h"

/**
* print_hex - This function prints hexa number in lowercase.
* @list: pointerr of arguments
* @params: the parameters
*
* Return: bytes
*/

int print_hex(va_list list, params_t *params)
{
int ch = 0;
char *stn;
unsigned long m;

if (params->l_modifier)
m = (unsigned long)va_arg(list, unsigned long);
else if (params->h_modifier)
m = (unsigned short int)va_arg(list, unsigned int);
else
m = (unsigned int)va_arg(list, unsigned int);
stn = convert(m, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && m)
{
*--stn = 'x';
*--stn = '0';
}
params->unsign = 1;
return (ch += print_number(stn, params));
}

/**
* print_HEX - a function that print hexa number in uppercase.
* @list: pointerr of arguments
* @params: structure.
* Return: bytes.
*/

int print_HEX(va_list list, params_t *params)
{
int ch = 0;
char *stn;
unsigned long m;

if (params->l_modifier)
m = (unsigned long)va_arg(list, unsigned long);
else if (params->h_modifier)
m = (unsigned short int)va_arg(list, unsigned int);
else
m = (unsigned int)va_arg(list, unsigned int);
stn = convert(m, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && m)
{
*--stn = 'X';
*--stn = '0';
}
params->unsign = 1;
return (ch += print_number(stn, params));
}

/**
* print_octal - a function that print octal number.
* @list: pointerr of arguments
* @params: structure.
* Return: bytes.
*/

int print_octal(va_list list, params_t *params)
{
int ch = 0;
char *stn;
unsigned long m;

if (params->l_modifier)
m = (unsigned long)va_arg(list, unsigned long);
else if (params->h_modifier)
m = (unsigned short int)va_arg(list, unsigned int);
else
m = (unsigned int)va_arg(list, unsigned int);
stn = convert(m, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && m)
*--stn = '0';
params->unsign = 1;

return (ch += print_number(stn, params));
}

/**
* print_binary - This function  prints binary number.
* @list: pointerr of arguments
* @params: structure
*
* Return: bytes
*/

int print_binary(va_list list, params_t *params)
{
int ch = 0;
unsigned int m = va_arg(list, unsigned int);
char *stn = convert(m, 2, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && m)
*--stn = '0';
params->unsign = 1;
return (ch += print_number(stn, params));
}
