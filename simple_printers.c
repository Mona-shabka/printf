#include "main.h"

/**
* print_rev - function that reverse string.
* @params: struction of parameters.
* @list: pointerr of arguments.
* Return: byte number.
*/

int print_rev(va_list list, params_t *params)
{
int sum = 0, length;
char *string = va_arg(list, char *);
(void)params;

if (string)
{
for (length = 0; *string; string++)
length++;
string--;
for (; length > 0; length--, string--)
sum += _putchar(*string);
}
return (sum);
}

/**
* print_from_to - function that prints letters address.
* @begin: start address.
* @end: end address.
* @except: excepting address.
* Return: byte number.
*/

int print_from_to(char *begin, char *end, char *except)
{
int sum = 0;

while (begin <= end)
{
if (begin != except)
sum += _putchar(*begin);
begin++;
}
return (sum);
}

/**
* print_rot13 - function that prints letters.
* @list: input string.
* @params: struction of parameters.
* Return: byte number.
*/

int print_rot13(va_list list, params_t *params)
{
int point, x;
int counter = 0;
char *m = va_arg(list, char *);
(void)params;
char array[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";

point = 0;
x = 0;
while (m[x])
{
if ((m[x] >= 'A' && m[x] <= 'Z') || (m[x] >= 'a' && m[x] <= 'z'))
{
point = m[x] - 65;
counter += _putchar(array[point]);
}
else
counter += _putchar(m[x]);
x++;
}
return (counter);
}
