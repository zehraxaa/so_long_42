/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:43 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:04:44 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long ptr, size_t *count)
{
	if (ptr == 0)
	{
		ft_print_str("(nil)", count);
	}
	else
	{
		ft_print_str("0x", count);
		ft_print_hex(ptr, 'x', count);
	}
}
