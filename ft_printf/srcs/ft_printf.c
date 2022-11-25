/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:03:34 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:52 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	find_token(const char **format, va_list *args)
{
	int	result;

	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			result += find_token(&format, &args);
		else
			result += write(STDOUT_FILENO, format, 1);
		format++;
	}
	va_end(args);
	return (result);
}
