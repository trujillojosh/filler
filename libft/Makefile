# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 22:45:57 by jtrujill          #+#    #+#              #
#    Updated: 2017/07/14 18:20:06 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
INC = -I includes/ft_printf.h
FLAGS = gcc -Wall -Wextra -Werror -c

MP = srcs/
CP = srcs/conversions/
SP = srcs/flags/
LP = srcs/libft/

MAIN = $(MP)ft_is_over.c $(MP)ft_itoa_dispatch.c $(MP)ft_next_arg.c \
	   $(MP)ft_printf.c $(MP)ft_remove_todo.c $(MP)ft_strinsert.c

CONV = $(CP)ft_c.c $(CP)ft_d.c $(CP)ft_o.c $(CP)ft_p.c $(CP)ft_percent.c \
	   $(CP)ft_s.c $(CP)ft_u.c $(CP)ft_x.c $(CP)ft_up_x.c

SPEC = $(SP)ft_0.c $(SP)ft_hash.c $(SP)ft_minus.c $(SP)ft_plus.c \
	   $(SP)ft_precision.c $(SP)ft_space.c $(SP)ft_width.c

LIBFT_P = $(LP)ft_atoi.c $(LP)ft_bzero.c $(LP)ft_cd_freq.c \
		  $(LP)ft_char_count.c $(LP)ft_int_len.c $(LP)ft_int_len_ext.c \
		  $(LP)ft_isalnum.c $(LP)ft_isalpha.c $(LP)ft_isascii.c \
		  $(LP)ft_isdigit.c $(LP)ft_isprint.c $(LP)ft_itoa.c \
		  $(LP)ft_itoa_base.c $(LP)ft_itoa_l.c $(LP)ft_itoa_ll.c \
		  $(LP)ft_itoa_m.c $(LP)ft_itoa_s.c $(LP)ft_itoa_t.c \
		  $(LP)ft_itoa_u.c $(LP)ft_itoa_ul.c $(LP)ft_itoa_ull.c \
		  $(LP)ft_itoa_um.c $(LP)ft_itoa_us.c $(LP)ft_lstadd.c \
		  $(LP)ft_lstdel.c $(LP)ft_lstdelone.c $(LP)ft_lstiter.c \
		  $(LP)ft_lstmap.c $(LP)ft_lstnew.c $(LP)ft_lstsize.c \
		  $(LP)ft_memalloc.c $(LP)ft_memccpy.c $(LP)ft_memchr.c \
		  $(LP)ft_memcmp.c $(LP)ft_memcpy.c $(LP)ft_memdel.c \
		  $(LP)ft_memmove.c $(LP)ft_memset.c $(LP)ft_print_hex.c \
		  $(LP)ft_print_list.c $(LP)ft_putchar.c $(LP)ft_putchar_fd.c \
		  $(LP)ft_putendl.c $(LP)ft_putendl_fd.c $(LP)ft_putnbr.c \
		  $(LP)ft_putnbr_fd.c $(LP)ft_putstr.c $(LP)ft_putstr_fd.c \
		  $(LP)ft_str_replace.c $(LP)ft_strcat.c $(LP)ft_strchr.c \
		  $(LP)ft_strclr.c $(LP)ft_strcmp.c $(LP)ft_strcpy.c \
		  $(LP)ft_strdel.c $(LP)ft_strdup.c $(LP)ft_strequ.c \
		  $(LP)ft_striter.c $(LP)ft_striteri.c $(LP)ft_strjoin.c \
		  $(LP)ft_strlcat.c $(LP)ft_strlen.c $(LP)ft_strmap.c \
		  $(LP)ft_strmapi.c $(LP)ft_strncat.c $(LP)ft_strncmp.c \
		  $(LP)ft_strncpy.c $(LP)ft_strnequ.c $(LP)ft_strnew.c \
		  $(LP)ft_strnstr.c $(LP)ft_strrchr.c $(LP)ft_strrev.c \
		  $(LP)ft_strsplit.c $(LP)ft_strstr.c $(LP)ft_strsub.c \
		  $(LP)ft_strtrim.c $(LP)ft_titoa_base.c $(LP)ft_tolower.c \
		  $(LP)ft_toupper.c $(LP)ft_uitoa_base.c $(LP)ft_uint_len_ext.c \
		  $(LP)ft_ulitoa_base.c $(LP)ft_ullitoa_base.c $(LP)ft_umitoa_base.c \
		  $(LP)ft_until.c $(LP)ft_usitoa_base.c $(LP)ft_wspace_check.c \
		  $(LP)get_next_line.c $(LP)ft_llitoa_base.c $(LP)ft_putstr_err.c \
		  $(LP)ft_lstend.c

SRCS = $(MAIN) $(CONV) $(SPEC) $(LIBFT_P)

OBJS = ft_is_over.o ft_itoa_dispatch.o ft_next_arg.o ft_printf.o \
	   ft_remove_todo.o ft_strinsert.o ft_c.o ft_d.o ft_o.o ft_p.o \
	   ft_percent.o ft_s.o ft_u.o ft_x.o ft_up_x.o ft_0.o ft_hash.o \
	   ft_minus.o ft_plus.o ft_precision.o ft_space.o ft_width.o \
	   ft_atoi.o ft_bzero.o ft_cd_freq.o ft_char_count.o ft_int_len.o \
	   ft_int_len_ext.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	   ft_isdigit.o ft_isprint.o ft_itoa.o ft_itoa_base.o ft_itoa_l.o \
	   ft_itoa_ll.o ft_itoa_m.o ft_itoa_s.o ft_itoa_t.o ft_itoa_u.o \
	   ft_itoa_ul.o ft_itoa_ull.o ft_itoa_um.o ft_itoa_us.o ft_lstadd.o \
	   ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o \
	   ft_lstsize.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	   ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_print_hex.o \
	   ft_print_list.o ft_putchar.o ft_putchar_fd.o ft_putendl.o \
	   ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o \
	   ft_putstr_fd.o ft_str_replace.o ft_strcat.o ft_strchr.o ft_strclr.o \
	   ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
	   ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
	   ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
	   ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strrev.o \
	   ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_titoa_base.o \
	   ft_tolower.o ft_toupper.o ft_uitoa_base.o ft_uint_len_ext.o \
	   ft_ulitoa_base.o ft_ullitoa_base.o ft_umitoa_base.o ft_until.o \
	   ft_usitoa_base.o ft_wspace_check.o get_next_line.o ft_llitoa_base.o \
	   ft_putstr_err.o ft_lstend.o

all: $(NAME)

$(NAME):
	@$(FLAGS) $(SRCS) $(INC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
