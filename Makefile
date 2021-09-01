# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 22:45:21 by hmoon             #+#    #+#              #
#    Updated: 2021/06/05 00:28:49 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

HEADER		:= libft.h

CFLAG		:= -Wall -Wextra -Werror

SRCS		:= ft_atoi.c ft_bzero.c ft_calloc.c \
			  ft_isalnum.c ft_isalpha.c \
			  ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_memccpy.c ft_memchr.c \
			  ft_memcmp.c ft_memchr.c ft_memcpy.c \
			  ft_memmove.c ft_memset.c \
			  ft_strchr.c ft_strdup.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c \
			  ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			  ft_tolower.c ft_toupper.c \
			  ft_substr.c ft_strjoin.c \
			  ft_strtrim.c ft_split.c \
			  ft_itoa.c ft_strmapi.c \
			  ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c

BONUS		:= ft_lstnew.c ft_lstadd_front.c \
			  ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c \
			  ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c

OBJS		:= ft_atoi.o ft_bzero.o ft_calloc.o \
			  ft_isalnum.o ft_isalpha.o \
			  ft_isascii.o ft_isdigit.o ft_isprint.o \
			  ft_memccpy.o ft_memchr.o \
			  ft_memcmp.o ft_memchr.o ft_memcpy.o \
			  ft_memmove.o ft_memset.o \
			  ft_strchr.o ft_strdup.o ft_strlcat.o \
			  ft_strlcpy.o ft_strlen.o \
			  ft_strncmp.o ft_strnstr.o ft_strrchr.o \
			  ft_tolower.o ft_toupper.o \
			  ft_substr.o ft_strjoin.o \
			  ft_strtrim.o ft_split.o \
			  ft_itoa.o ft_strmapi.o \
			  ft_putchar_fd.o ft_putstr_fd.o \
			  ft_putendl_fd.o ft_putnbr_fd.o

BONUS_OBJS	:= ft_lstnew.o ft_lstadd_front.o \
			  ft_lstsize.o ft_lstlast.o \
			  ft_lstadd_back.o ft_lstdelone.o \
			  ft_lstclear.o ft_lstiter.o\
			  ft_lstmap.o

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $@ $^

.PHONY: bonus
bonus:
	@make WITH_BONUS=1 all

*.o: *.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

.PHONY: clean
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all
