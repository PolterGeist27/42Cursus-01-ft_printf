/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:13:56 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/05 14:18:46 by diogmart         ###   ########.fr       */
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
		ft_addsign(&to_print, '-', token);
		return (to_print);
	}
	tmp = ft_calloc((lenght + 1), (sizeof(char)));
	tmp[0] = '-';
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

static int	handle_negative(t_token *token, char **to_print)
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

int	print_i(t_token *token, int i)
{
	int		bytes;
	char	*to_print;

	bytes = 0;
	if (i >= 0)
		return (print_u(token, i));
	to_print = ft_itoa((long int)i * -1);
	bytes += handle_negative(token, &to_print);
	free(to_print);
	return (bytes);
}
