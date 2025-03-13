/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:05:01 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:05:02 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char c, va_list ap, size_t *count)
{
	if (c == 'c')
		ft_print_char(va_arg(ap, int), count);
	else if (c == 's')
		ft_print_str(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(ap, int), count);
	else if (c == 'p')
		ft_print_ptr(va_arg(ap, unsigned long), count);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(ap, unsigned int), c, count);
	else if (c == 'u')
		ft_print_unsigned(va_arg(ap, unsigned int), count);
	else if (c == '%')
		ft_print_char('%', count);
	else
	{
		write(1, &c, 1);
		(*count)++;
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	size_t	count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_print_format(*(++format), ap, &count);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(ap);
	return (count);
}
