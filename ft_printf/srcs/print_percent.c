/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:14:23 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/02 10:20:06 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	print_percent(t_token *token)
{
	int	bytes;

	bytes = 0;
	if (token->minus == 1)
	{
		bytes += write(STDOUT_FILENO, '%', 1);
		while (token->padding-- > 1)
			bytes += write(STDOUT_FILENO, ' ', 1);
	}
	else
	{
		if (token->zero)
		{
			while (token->padding-- > 1)
				bytes += write(STDOUT_FILENO, '0', 1);
			bytes += write(STDOUT_FILENO, '%', 1);
		}
		else
		{
			while (token->padding-- > 1)
				bytes += write(STDOUT_FILENO, ' ', 1);
			bytes += write(STDOUT_FILENO, '%', 1);
		}
	}
	return (bytes);
}
