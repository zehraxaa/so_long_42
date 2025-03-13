/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:36 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:04:37 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int num, size_t *count)
{
	if (num == -2147483648)
	{
		ft_print_str("-2147483648", count);
		return ;
	}
	else if (num < 0)
	{
		ft_print_char('-', count);
		ft_print_int(-num, count);
	}
	else
	{
		if (num >= 10)
		{
			ft_print_int((num / 10), count);
		}
		ft_print_char(((num % 10) + '0'), count);
	}
}
