/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:18:06 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/25 12:06:17 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//	ft_printf.c
int ft_printf(const char *, ...);

//	token
typedef struct s_token
{
	char	type;

	int		zero;
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		dot;

}	t_token;

# define TYPE "cspdiuxX%"


#endif