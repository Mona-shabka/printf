#include "main.h"

/**
* _puts - a function that print string with new line.
* @string: input string.
* Return: length of string.
*/

int _puts(char *string)
{
char *x = string;

while (*string)
_putchar(*string++);
return (string - x);
}

/**
* _putchar - a function that write the character to stdout.
* @character: letter that to be print.
* Return: 1 (success) or -1 (fail).
*/

int _putchar(int character)
{
static char buf[OUTPUT_BUF_SIZE];
static int i;

if (character == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (character != BUF_FLUSH)
buf[i++] = character;
return (1);
}
