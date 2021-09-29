/*                                                                                                                                                                                                                                             
** EPITECH PROJECT, 2020                                                                                                                                                                                                                       
** MY_PRINTF                                                                                                                                                                                                                                 
** File description:                                                                                                                                                                                                                           
** NO DESCRIPTION FOUND                                                                                                                                                                                                                        
*/

#include <stdarg.h>
#include "../../include/my.h"

void step_two(va_list l, int i, char const *s)
{
    if (s[i+1] == 'l')
        if (s[i+2] == 'd')
            put_long_int(va_arg(l, long int));
}

void step_one(va_list l, int i, char const *s)
{
    if (s[i+1] == 'c')
        my_putchar(va_arg(l, int));
    if (s[i+1] == 'i' || s[i+1] == 'd')
        my_put_nbr(va_arg(l, int));
    if (s[i+1] == 's' || s[i+1] == 'S')
        my_putstr(va_arg(l, char *));
    if (s[i+1] == 'p')
        address(va_arg(l, long long));
    if (s[i+1] == 'u')
        put_unsigned_int(va_arg(l, unsigned int));
    if (s[i+1] == 'x')
        to_hexadecimal_min(va_arg(l, int));
    if (s[i+1] == 'X')
        to_hexadecimal_maj(va_arg(l, int));
    if (s[i+1] == 'o')
        to_octal(va_arg(l, int));
    if (s[i+1] == '%')
        my_putchar('%');
    step_two(l, i, s);
}

void my_printf(char const *s, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, s);
    while (s[i] != '\0') {
        if(s[i] == '%') {
            step_one(ap, i, s);
            if(s[i+1] == 'l' && s[i+2] == 'd')
                i++;
            i = i + 2;
        }
        my_putchar(s[i]);
        i++;
    }
  va_end(ap);
}