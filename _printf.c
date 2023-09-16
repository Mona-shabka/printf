#include "main.h"

/**
* _printf - a function that produces output according to a format.
* @format: format is a character string.
* Return: the number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
va_list list;
char *paragraph, *begin;
int sum = 0;
params_t params = PARAMS_INIT;
va_start(list, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (paragraph = (char *)format; *paragraph; paragraph++)
{
init_params(&params, list);
if (*paragraph != '%')
{
sum += _putchar(*paragraph);
continue;
}
begin = paragraph;
paragraph++;
while (get_flag(paragraph, &params))
{
paragraph++;
}
paragraph = get_width(paragraph, &params, list);
paragraph = get_precision(paragraph, &params, list);
if (get_modifier(paragraph, &params))
paragraph++;
if (!get_specifier(paragraph))
sum += print_from_to(begin, paragraph,
params.l_modifier || params.h_modifier ? paragraph - 1 : 0);
else
sum += get_print_func(paragraph, list, &params);
}
_putchar(BUF_FLUSH);
va_end(list);
return (sum);
}
