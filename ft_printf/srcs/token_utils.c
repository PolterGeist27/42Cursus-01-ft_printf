/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:01:34 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/28 13:25:05 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	init_token(t_token **token)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (!(*token))
		return (1);
	(*token)->type = 0;
	(*token)->zero = 0;
	(*token)->minus = 0;
	(*token)->plus = 0;
	(*token)->hash = 0;
	(*token)->space = 0;
	(*token)->dot = 0;
	(*token)->padding = 0;
	(*token)->precision = 0;
	(*token)->asterisk = 0;
	return (0);
}

int	get_flags(t_token **token, const char *c, va_list *args)
{
	if (c == '-')
		(*token)->minus = 1;
	if (c == '0' && (*token)->minus == 0)
		(*token)->zero = 1;
	if (c == '+')
		(*token)->plus = 1;
	if (c == '#')
		(*token)->hash = 1;
	if (c == ' ')
		(*token)->space = 1;
	if (c == '.')
		(*token)->dot = 1;
	if ((c >= '0' && c <= '9') || c == '*')
		return(get_value(&token, c, args));
	return (1);
}

int	get_value(t_token **token, const char *c, va_list *args)
{
	int value;

	if (*c == '*')
	{
		(*token)->asterisk = 1;
		value = va_arg((*args), int);
	}
	else
		value = ft_atoi(c);
	
	return (ft_nbrlen(value, 10));
}