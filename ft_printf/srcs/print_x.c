/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:15:40 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/05 15:13:25 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_str_toupper(char **s)
{
	char	*str;

	str = *s;
	if (!str)
		return ;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

static char	*build_str(char *to_print, int lenght, t_token *token, char padding)
{
	int		nbrlen;
	char	*tmp;

	nbrlen = ft_strlen(to_print);
	if (nbrlen >= lenght)
		return (to_print);
	tmp = ft_calloc((lenght + 1), (sizeof(char)));
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

static int	handle_others(t_token *token, char **to_print)
{
	if (token->dot == 1)
		*to_print = build_str(*to_print, token->precision, token, '0');
	else if (token->minus == 1)
		*to_print = build_str(*to_print, token->padding, token, ' ');
	else if (token->zero == 1)
		*to_print = build_str(*to_print, token->padding, token, '0');
	else
		*to_print = build_str(*to_print, token->padding, token, ' ');
	return (ft_strlen(*to_print));
}
#include <stdio.h>
int	print_x(t_token *token, unsigned int x)
{
	int		bytes;
	char	*to_print;

	bytes = 0;
	if (token->hash == 1)
	{
		bytes += print_p(token, (unsigned long long)x);
		return (bytes);
	}
	to_print = ft_itoa_hex((unsigned long long)x);
	bytes += handle_others(token, &to_print);
	if (token->type == 'X')
		ft_str_toupper(&to_print);
	ft_putstr_fd(to_print, STDOUT_FILENO);
	free(to_print);
	return (bytes);
}
