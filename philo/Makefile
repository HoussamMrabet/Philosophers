NAME = philo

SRCS = main.c utils-0.c utils-1.c custom_functions_0.c custom_functions_1.c parser.c init_data.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
FLAGS = -g -pthread
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c philo.h error_msgs.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean