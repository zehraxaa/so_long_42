/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:20 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:04:24 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned long num, char c, size_t *count)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (num == 0)
	{
		ft_print_char('0', count);
		return ;
	}
	if (num < 16)
		ft_print_char(hex[num], count);
	else
	{
		ft_print_hex(num / 16, c, count);
		ft_print_hex(num % 16, c, count);
	}
}
