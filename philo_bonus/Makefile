NAME = philo_bonus

SRCS = main_bonus.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
FLAGS = -g -pthread
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $< -o $@

%.o : %.c philo_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean