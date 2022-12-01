/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:15:08 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/01 11:32:48 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int handle_dot(t_token *token, unsigned int u)
{
	int 	bytes;
	int		i;
	int 	len;
	char	*nbr;
	char	padding;

	bytes = 0;
	i = 0;
	len = ft_nbrlen(u, 10);
	nbr = ft_itoa(u);
	if (token->dot == 1)
	{
		while (len < token->precision--)
			bytes += write(STDOUT_FILENO, "0", 1);
		while (nbr[i] != '\0')
			bytes += write(STDOUT_FILENO, &(nbr[i++]), 1);
	}
	return (bytes);
}

int	handle_minus(t_token *token, unsigned int u)
{
	int 	bytes;
	int		i;
	int 	len;
	char	*nbr;
	char	padding;

	bytes = 0;
	i = 0;
	len = ft_nbrlen(u, 10);
	nbr = ft_itoa(u);
	padding = ft_getpaddingchar(token);
	if (token->minus == 1)
	{
		while (nbr[i] != '\0')
			bytes += write(STDOUT_FILENO, &(nbr[i++]), 1);
		while (token->padding-- > len)
			bytes += write(STDOUT_FILENO, &padding, 1);
	}
	else
	{
		while (token->padding-- > len)
			bytes += write(STDOUT_FILENO, &padding, 1);
		while (nbr[i] != '\0')
			bytes += write(STDOUT_FILENO, &(nbr[i++]), 1);
	}
	return (bytes);
}

int	print_u(t_token *token, unsigned int u)
{
	int 	bytes;

	bytes = 0;
	bytes += handle_dot(token, u);
	bytes += handle_minus(token, u);
	return (bytes);
}
