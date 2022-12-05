/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:18:06 by diogmart          #+#    #+#             */
/*   Updated: 2022/12/05 14:51:08 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

//	ft_printf.c
int		ft_printf(const char *str, ...);

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

int		init_token(t_token **token);
int		get_flags(t_token **token, const char *c);
int		get_value(t_token **token, const char *c);

// prints
int		print_c(t_token *token, unsigned char c);
int		print_i(t_token *token, int i);
int		print_p(t_token *token, unsigned long long p);
int		print_percent(t_token *token);
int		print_s(t_token *token, char *str);
int		print_u(t_token *token, unsigned int u);
int		print_x(t_token *token, unsigned int x);

// utils
int		ft_nbrlen(int nbr);
void	ft_addsign(char **to_print, char sign, t_token *token);
int		ft_hexlen(unsigned long long n);
char	*ft_itoa_hex(unsigned long long n);

# define TYPE "cspdiuxX%"

#endif