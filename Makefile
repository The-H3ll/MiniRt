# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 21:34:55 by molabhai          #+#    #+#              #
#    Updated: 2020/02/29 21:36:43 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = camera.c check_object.c help_take_coordinate.c light.c minirt.c minirt_utils.c \
	  minirt_utils2.c minirt_utils3.c object_inter.c object_inter2.c object_inter3.c \
	  take_coordinates.c take_coordinates2.c write_utils.c main.c calculus.c calculus2.c \
	  ft_memset.c ft_atoi.c ft_isdigit.c get_next_line.c get_next_line_utils.c save_image.c \
	  camera_helper.c check_object_helper.c minirt_utils4.c light_helper.c take_coordinate_helper.c \
	  ft_memcpy.c error_handler.c extra_help.c extra_error_handler.c

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I /usr/local/include  $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o miniRT

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
