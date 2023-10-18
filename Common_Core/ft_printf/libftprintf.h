/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:25:43 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:25:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ... );
int	count_args(const char *str);
int	write_spe(const char *str, va_list valst, int count);
int	write_c(va_list valst, int count);
int	write_s(va_list valst, int count);
int	write_i(va_list valst, int count);
int	nb_len(int long nb);
int	write_d(va_list valst, int count);
int	write_double(double nb, int dec, int size);
int	ft_power(int base, int exp);
