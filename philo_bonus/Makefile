NAME = philo_bonus

SRCS = main_bonus.c utils-0_bonus.c utils-1_bonus.c custom_functions_0_bonus.c custom_functions_1_bonus.c parser_bonus.c init_data_bonus.c itoa.c booleans_bonus.c dinning-0_bonus.c dinning-1_bonus.c

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