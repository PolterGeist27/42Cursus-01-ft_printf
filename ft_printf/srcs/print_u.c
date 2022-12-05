/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:15:08 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/05 14:18:58 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*build_str(char *to_print, int lenght, t_token *token, char padding)
{
	int		nbrlen;
	char	*tmp;

	nbrlen = ft_strlen(to_print);
	if (nbrlen >= lenght)
	{
		ft_addsign(&to_print, '+', token);
		return (to_print);
	}
	tmp = ft_calloc((lenght + 1), (sizeof(char)));
	if (token->plus == 1)
		*tmp++ = '+';
	if (token->minus == 1)
	{
		ft_strlcat(tmp, to_print, lenght + 1);
		while (nbrlen < lenght)
			tmp[++nbrlen] = ' ';
	}
	else
	{
		while (++nbrlen < lenght)
			*tmp++ = padding;
		ft_strlcat(tmp, to_print, lenght + 1);
	}
	return (tmp);
}

static int	handle_positive(t_token *token, char **to_print)
{
	if (token->dot == 1)
		*to_print = build_str(*to_print, token->precision, token, '0');
	else if (token->minus == 1)
		*to_print = build_str(*to_print, token->padding, token, ' ');
	else if (token->zero == 1)
		*to_print = build_str(*to_print, token->padding, token, '0');
	else
		*to_print = build_str(*to_print, token->padding, token, ' ');
	ft_putstr_fd(*to_print, STDOUT_FILENO);
	return (ft_strlen(*to_print));
}

int	print_u(t_token *token, unsigned int u)
{
	int		bytes;
	char	*to_print;

	bytes = 0;
	to_print = ft_itoa(u);
	bytes += handle_positive(token, &to_print);
	free(to_print);
	return (bytes);
}
