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
va_list i;
char *par, *b;

int sum = 0;
params_t params = PARAMS_INIT;
va_start(i, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (par = (char *)format; *par; par++)
{
init_params(&params, i);
if (*par != '%')
{
sum += mo_putchar(*par);
continue;
}
b = par;
par++;
while (get_flag(par, &params))
{
par++;
}
par = get_width(par, &params, i);
par = get_precision(par, &params, i);
if (get_modifier(par, &params))
par++;
if (!get_specifier(par))
sum += print_from_to(b, par,
params.l_modifier || params.h_modifier ? par - 1 : 0);
else
sum += get_print_func(par, i, &params);
}
mo_putchar(BUF_FLUSH);
va_end(i);

return (sum);
}
