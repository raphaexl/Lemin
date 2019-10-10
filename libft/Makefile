# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 11:05:48 by ebatchas          #+#    #+#              #
#    Updated: 2019/10/08 14:16:49 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = incs

DONE_COLOR = \x1b[31;03m
EOC = \033[0m

SRCS_NO_PREFIX = ft_atoi.c ft_atof.c ft_ftoa.c ft_isalnum.c ft_isascii.c ft_isalpha.c\
	ft_isdigit.c ft_isprint.c ft_bzero.c ft_lstnew.c ft_lstnew_ptr.c ft_lstadd.c\
	ft_lstadd2.c ft_lstdelone.c ft_lstdel.c ft_lstdel_ptr.c ft_lstiter.c ft_lstdup.c\
	ft_lstswap.c ft_lstreverse.c ft_lstjoin.c ft_lstlen.c ft_lstmap.c ft_lstpop.c\
	ft_lstpop_ptr.c ft_lstpushback.c ft_tree_new.c ft_tree_new_ptr.c ft_tree_prefix.c \
	ft_tree_postfix.c ft_tree_infix.c ft_tree_add_sorted.c ft_tree_add_sorted_mul.c \
	ft_tree_len.c ft_tree_del.c ft_tree_del_ptr.c ft_tree_del_value.c ft_tree_at.c \
	ft_min.c ft_max.c ft_memalloc.c ft_memcpy.c ft_memchr.c ft_memccpy.c ft_memdel.c \
	ft_memcmp.c ft_memset.c ft_round.c ft_read_line.c\
	ft_memmove.c ft_power.c ft_len_split.c ft_free_split.c ft_free_turn.c ft_strjoin_3.c\
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
	ft_putstr.c ft_putstr_fd.c ft_strclr.c ft_strcat.c ft_strcpy.c ft_strchr.c ft_strcmp.c\
	ft_strdel.c ft_strdup.c ft_striter.c ft_strequ.c ft_striteri.c ft_strlen.c ft_strlcat.c\
	ft_strmap.c ft_strjoin.c ft_strmapi.c ft_strncat.c ft_strncpy.c ft_strncmp.c ft_strnequ.c\
	ft_strns.c ft_strncat.c ft_strnstr.c ft_strnew.c ft_newstr.c ft_strrchr.c ft_strstr.c\
	ft_tolower.c ft_toupper.c ft_strsub.c ft_strsplit.c ft_strtrim.c ft_itoa.c ft_itoa_base.c\
	ft_get_next_line.c ft_realloc.c ft_vector_func1.c ft_vector_func2.c conversion.c newconversion.c\
	parseconversion.c printconversion.c float_conversion.c print_spacing.c print_numbers.c print_strings.c\
	print_float.c print_wint.c print_wstr.c print_error.c precision.c width.c tally_print.c double_tools.c\
	double_calc1.c double_calc2.c double_utils.c double_ops.c color.c ft_printf.c

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))

INC_PATH = -I $(INCLUDESDIR)
INCLUDES_NO_PREFIX = libft.h structs.h color.h
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

CFLAGS += $(INC_PATH)

all: $(BINDIR)/$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BINDIR)/$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "$(DONE_COLOR) libft compiled successfully !$(EOC)"

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJDIR)
	@echo "$(DONE_COLOR) libft object files successfully removed !$(EOC)"

fclean: clean
	@rm -f $(BINDIR)/$(NAME)
	@echo "$(DONE_COLOR) libft.a files successfully removed !$(EOC)"

re: fclean all

norme:
	norminette $(HEADDIR)/*.h
	norminette $(SRCDIR)/*.c

.PHONY: all clean fclean re norme
