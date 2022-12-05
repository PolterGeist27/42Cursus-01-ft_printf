/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:14:46 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/05 11:47:59 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_c(t_token *token, unsigned char c)
{
	int	bytes;

	bytes = 0;
	if (token->minus == 1)
	{
		bytes += write(STDOUT_FILENO, &c, 1);
		while (token->padding-- > 1)
			bytes += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (token->padding-- > 1)
			bytes += write(STDOUT_FILENO, " ", 1);
		bytes += write(STDOUT_FILENO, &c, 1);
	}
	return (bytes);
}
