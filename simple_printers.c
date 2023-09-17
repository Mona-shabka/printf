#include "main.h"

/**
* print_rev - function that reverse string.
* @params: struction of parameters.
* @list: pointerr of arguments.
* Return: byte number.
*/

int print_rev(va_list list, params_t *params)
{
int length, sum = 0;
char *string = va_arg(list, char *);
(void)params;

if (string)
{
for (length = 0; *string; string++)
length++;
string--;
for (; length > 0; length--, string--)
sum += mo_putchar(*string);
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
sum += mo_putchar(*begin);
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
int x, point;
int counter = 0;
char array[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
char *m = va_arg(list, char *);
(void)params;

point = 0;
x = 0;
while (m[x])
{
if ((m[x] >= 'A' && m[x] <= 'Z') || (m[x] >= 'a' && m[x] <= 'z'))
{
point = m[x] - 65;
counter += mo_putchar(array[point]);
}
else
counter += mo_putchar(m[x]);
x++;
}
return (counter);
}
