/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:42:58 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:37:08 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_isdigit(int nb);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_bzero(void *str, size_t n);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t nb);
char				*ft_strstr(const char *s, const char *tf);
char				*ft_itoa(int n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s, const char *tf, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				**ft_strsplit(char const *s, char c);

void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memalloc(size_t size);

size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);

int					ft_int_len(int nb);
int					ft_wspace_check(char c);
size_t				ft_until(const char *str, char c);
int					ft_cd_freq(const char *s, char c);
char				*ft_strrev(char *str);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_print_list(t_list *lst);
int					ft_lstsize(t_list *lst);
int					get_next_line(const int fd, char **line);
int					ft_char_count(char *str, char c);
void				ft_print_hex(int nb);
char				*ft_itoa_base(int value, int base);
int					ft_int_len_ext(int nb, int base);
char				*ft_uitoa_base(unsigned int value, int base);
int					ft_uint_len_ext(unsigned int nb, int base);
void				ft_str_replace(char **old, char *new);
char				*ft_itoa_t(size_t n);
char				*ft_itoa_l(long n);
char				*ft_itoa_ll(long long n);
char				*ft_itoa_s(short n);
char				*ft_itoa_ul(unsigned long n);
char				*ft_itoa_ull(unsigned long long n);
char				*ft_itoa_us(unsigned short n);
char				*ft_itoa_m(intmax_t n);
char				*ft_itoa_um(uintmax_t n);
char				*ft_itoa_u(unsigned int n);
char				*ft_usitoa_base(unsigned short value, int base);
char				*ft_ulitoa_base(unsigned long value, int base);
char				*ft_ullitoa_base(unsigned long long value, int base);
char				*ft_umitoa_base(uintmax_t value, int base);
char				*ft_titoa_base(size_t value, int base);
char				*ft_llitoa_base(long long value, long long base);
void				ft_putstr_err(const char *s);
t_list				*ft_lstend(t_list *head, char *new);

#endif
