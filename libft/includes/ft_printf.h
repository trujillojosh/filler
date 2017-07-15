/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:32 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/09 16:29:10 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *input, ...);
int		ft_plus(char *str, char *todo, int start);
int		ft_minus(char *str, char *todo, int start);
int		ft_0(char *str, char *todo, int start, int prec);
int		ft_hash(char *str, char *todo, int start);
int		ft_space(char *str, char *todo, int start);

int		ft_up_x(va_list ap, char **s1, char *todo);
int		ft_c(va_list ap, char **s1);
int		ft_d(va_list ap, char **s1, char *todo);
int		ft_o(va_list ap, char **s1, char *todo);
int		ft_p(va_list ap, char **s1);
int		ft_s(va_list ap, char **s1, int pres);
int		ft_u(va_list ap, char **s1, char *todo);
int		ft_x(va_list ap, char **s1, char *todo);
int		ft_percent(char **s1);

int		ft_next_arg(va_list ap, char **str);
char	*ft_strinsert(char *s1, char *s2, int mode);
int		ft_is_over(char c, int mode);
int		ft_width(char *str, char *todo, int start, int empty);
char	*ft_remove_todo(char *todo, char *remove);
int		find_precision(char *todo);
int		ft_precision(char *str, int start, char *todo, int prec);
char	*ft_itoa_dispatch(void *nb, char *todo, int base);

#endif
