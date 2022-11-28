/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:14:46 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/28 13:57:18 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int	print_c(t_token *token, unsigned char c)
{
	int	bytes;

	bytes = 0;
	if (token->minus == 1)
	{
		bytes += write(STDOUT_FILENO, &c, 1);
		while (token->padding-- > 1)
			bytes += write(STDOUT_FILENO, ' ', 1);
	}
	else
	{
		while (token->padding-- > 1)
			bytes += write(STDOUT_FILENO, ' ', 1);
		bytes += write(STDOUT_FILENO, &c, 1);
	}
	return (bytes);
}