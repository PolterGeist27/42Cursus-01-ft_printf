/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:18:06 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/01 12:51:34 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

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
	int		padding;
	int		precision;

}	t_token;

int	init_token(t_token **token);
int	get_flags(t_token **token, const char *c, va_list *args);

// prints
int	print_c(t_token *token, unsigned char c);
int	print_i(t_token *token, int i);
int	print_p(t_token *token, unsigned long p);
int	print_percent(t_token *token);
int	print_s(t_token *token, unsigned char *str);
int	print_u(t_token *token, unsigned int u);
int	print_x(t_token *token, unsigned int x);

// utils
int	ft_nbrlen(int nbr, int base);
void	ft_addsign(char **to_print, char sign);

# define TYPE "cspdiuxX%"


#endif