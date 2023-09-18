#include "main.h"

/**
* print_rev - This function reverses string.
* @params: parameters
* @list: pointerr of arguments
*
* Return: byte number
*/

int print_rev(va_list list, params_t *params)
{
int length;
int sum = 0;
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
* print_from_to - This function prints letters address
* @begin: start address
* @end: end address
* @except: excepting address
*
* Return: summ
*
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
* print_rot13 - This function prints letters
* @list: input string
* @params: struction of parameters
*
* Return: byte number
*/

int print_rot13(va_list list, params_t *params)
{
int x, point, counter = 0;
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
