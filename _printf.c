#include "main.h"

/**
* _printf - This function produces output according to a format.
* @format: a format specifier
*
* Return: the number of characters
*
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
sum += mo_putchar(*paragraph);
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
mo_putchar(BUF_FLUSH);
va_end(list);

return (sum);
}
