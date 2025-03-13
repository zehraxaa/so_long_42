/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:53 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:04:54 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int num, size_t *count)
{
	if (num >= 10)
	{
		ft_print_unsigned(num / 10, count);
	}
	ft_print_char(num % 10 + '0', count);
}
