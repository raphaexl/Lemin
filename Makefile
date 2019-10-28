# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchahid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 22:45:50 by kchahid           #+#    #+#              #
#    Updated: 2019/10/28 22:45:54 by kchahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

PWD=\"$(shell pwd)\"

SRCDIR = src
OBJDIR = obj
BINDIR = .
HEADDIR = header

LIBFTDIR=libft
LIBFT_HEADDIR=header
LIBFT = $(LIBFTDIR)/libft.a

DONE_COLOR=\x1b[34;03m
EOC=\033[0m

SRCS_NO_PREFIX = backtrack_bfs.c bfs_group.c bfs_path.c bfs_room.c bfs_score.c bfs_tool.c bfs_copy.c breadth_first_search.c error.c free_env.c init.c display.c solve.c link_bfs.c main.c ant.c print.c parse_ant.c parse_link.c parse_room.c queue_tools.c read_line.c tools_element.c special_case.c output.c

INCS_NO_PREFIX  = lem_in.h

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCS = $(addprefix $(HEADDIR)/, $(INCS_NO_PREFIX))

INC = -I $(HEADDIR) -I $(LIBFTDIR)/$(LIBFT_HEADDIR)

CFLAGS=-DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LDFLAGS= -L $(LIBFTDIR) -lft

NAME=lem-in

all:
	make -C $(LIBFTDIR) all
	make $(BINDIR)/$(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(BINDIR)/$(NAME) : $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) compiled successfully !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@make clean -C $(LIBFTDIR)
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) objs successfully removed !$(EOC)"

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -rf $(BINDIR)/$(NAME)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) files successfully removed !$(EOC)"

re: fclean all

norme:
	make norme -C $(LIBFTDIR)
	norminette $(HEADDIR)/*.h
	norminette $(SRCDIR)/*.c

.PHONY: all clean fclean re norme
