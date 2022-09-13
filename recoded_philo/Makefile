NAME = PHILO

SRCS = main.c ft_atoi.c timeSeter.c

OBJS = ${SRCS.c:.o}

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) philo.h
	cc -Wall -Wextra -Werror $(SRCS) -pthread -o $(NAME)

fclean :
	rm -rf $(NAME) $(OBJS)
clean : 
	rm -rf $(NAME)
re : fclean all