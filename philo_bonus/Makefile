# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 07:24:31 by hmrabet           #+#    #+#              #
#    Updated: 2024/03/25 07:24:32 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = main_bonus.c utils-0_bonus.c utils-1_bonus.c custom_functions_0_bonus.c custom_functions_1_bonus.c parser_bonus.c init_data_bonus.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
FLAGS = -g -pthread
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c philo_bonus.h error_msgs_bonus.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean