/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:01:34 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:38 by diogmart         ###   ########.fr       */
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
	return (0);
}

