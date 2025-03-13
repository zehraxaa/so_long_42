/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:48 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:04:49 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, size_t *count)
{
	int	i;

	if (str == NULL)
	{
		str = "(null)";
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}
