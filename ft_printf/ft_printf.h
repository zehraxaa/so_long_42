/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:05:27 by aaydogdu          #+#    #+#             */
/*   Updated: 2024/12/01 12:05:28 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_print_char(int c, size_t *count);
void	ft_print_str(char *str, size_t *count);
void	ft_print_int(int num, size_t *count);
void	ft_print_unsigned(unsigned int num, size_t *count);
void	ft_print_hex(unsigned long num, char c, size_t *count);
void	ft_print_ptr(unsigned long ptr, size_t *count);

#endif