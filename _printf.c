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
char *par, *begin;

int sum = 0;
params_t params = PARAMS_INIT;
va_start(list, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (par = (char *)format; *par; par++)
{
init_params(&params, list);
if (*par != '%')
{
sum += mo_putchar(*par);
continue;
}
begin = par;
par++;
while (get_flag(par, &params))
{
par++;
}
par = get_width(par, &params, list);
par = get_precision(par, &params, list);
if (get_modifier(par, &params))
par++;
if (!get_specifier(par))
sum += print_from_to(begin, par,
params.l_modifier || params.h_modifier ? par - 1 : 0);
else
sum += get_print_func(par, list, &params);
}
mo_putchar(BUF_FLUSH);
va_end(list);

return (sum);
}
