/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:03:34 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/24 13:51:57 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	while (*format != NULL)
	{
		if (*format == '%')
		{
			
		}
		
	}
	va_end(args);
	return (result);
}
