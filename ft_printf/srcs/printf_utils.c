/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:02:23 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/28 13:53:35 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int	ft_nbrlen(int nbr, int base)
{
	int	len;

	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / base;
	}
	return (len);
}
