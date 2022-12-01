/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:02:23 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/01 12:50:57 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_nbrlen(int nbr, int base)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr = nbr / base;
	}
	return (len);
}

void	ft_addsign(char **to_print, char sign)
{
	char	*tmp;
	int		len;
	
	len = ft_strlen(*to_print);
	tmp = malloc((len + 1) * sizeof(char));
	tmp[0] = sign;
	tmp[len + 1] = '\0';
	ft_strlcpy(tmp + 1, *to_print, len + 1);
	free(*to_print);
	*to_print = tmp;
}