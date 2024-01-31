NAME = philo

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
FLAGS = -g -pthread
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $< -o $@

%.o : %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean