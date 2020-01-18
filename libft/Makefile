# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 18:41:52 by molabhai          #+#    #+#              #
#    Updated: 2019/12/24 14:51:28 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADER = libft.h get_next_line.h

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memccpy.c ft_memchr.c ft_memcmp.c  \
	   ft_calloc.c ft_strdup.c ft_strlen.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
	   ft_strlcat.c ft_strnstr.c ft_substr.c  ft_strjoin.c  ft_strtrim.c ft_split.c \
	   ft_itoa.c  ft_strmapi.c  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_atoi.c ft_extend.c get_next_line.c get_next_line_utils.c


OBJ = $(SRCS:.c=.o)


BSRCS = ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c

BOBJ = $(BSRCS:.c=.o)

all : 
	$(CC) $(FLAGS) -c $(SRCS) $(HEADER)
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

$(NAME) : all
			

bonus :
	$(CC) $(FLAGS) -c $(BSRCS) $(HEADER)
	ar rc $(NAME) $(BOBJ)
	ranlib $(NAME)

clean :
		$(RM) $(OBJ) $(NAME) $(BOBJ)

fclean : clean

re : fclean all

.PHONY: clean all fclean re bonus
