/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:13:56 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/02 10:35:56 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*build_str(char *to_print, int lenght, t_token *token, char padding)
{
	int		nbrlen;
	char	*tmp;
	int		i;

	nbrlen = ft_strlen(to_print);
	if (nbrlen <= lenght)
	{
		ft_addsign(&to_print, '-');
		return (to_print);
	}
	tmp = ft_calloc((lenght + 1), (sizeof(char)));
	tmp[0] = '-';
	if (token->minus == 1)
	{
		ft_strlcat(tmp, to_print, lenght + 1);
		while (nbrlen < lenght)
			tmp[++nbrlen] = ' ';			// ????
	}
	else
	{
		i = 1;
		while (i < (lenght - nbrlen))
			tmp[i++] = padding;
		ft_strlcat(tmp, to_print, lenght + 1);
	}
	return (tmp);
}

int	handle_negative(t_token *token, char **to_print)
{
	if (token->dot == 1)
		*to_print = build_str(*to_print, token->precision, token, '0');
	else if (token->minus == 1)
		*to_print = build_str(*to_print, token->padding, token, ' ');
	else if (token->zero == 1)
		*to_print = build_str(*to_print, token->padding, token, '0');
	else
		*to_print = build_str(*to_print, token->padding, token, ' ');
	ft_putstr_fd(to_print, STDOUT_FILENO);
	return (ft_strlen(*to_print));
}

int	print_i(t_token *token, int i)
{
	int 	bytes;
	char 	*to_print;

	bytes = 0;
	if (i >= 0)
		return (print_u(token, i));
	to_print = ft_itoa((long int)i * -1);
	bytes += handle_negative(token, &to_print);
	return (bytes);
}


int	init_token(t_token **token)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (!(*token))
		return (1);
	(*token)->type = 0;
	(*token)->zero = 0;
	(*token)->minus = 1;
	(*token)->plus = 0;
	(*token)->hash = 0;
	(*token)->space = 0;
	(*token)->dot = 0;
	(*token)->padding = 4;
	(*token)->precision = 0;
	return (0);
}

#include <stdio.h>

int main(void)
{
	t_token *token;
	int	i = -42;

	init_token(&token);
	print_i(token, i);
	printf("h\n%-4ih\n", i);
}

