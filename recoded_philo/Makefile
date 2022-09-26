NAME = PHILO

NAME_BONUS = philo_bonus

SRCS = mandatory/main.c mandatory/ft_atoi.c mandatory/timeSeter.c  mandatory/checker.c mandatory/destroy.c mandatory/parcing.c

SRCS_BONUS = bonus/init_bonus.c bonus/main_bonus.c bonus/ft_atoi.c 

OBJS = ${SRCS.c:.o}

OBJS_BONUS = ${SRCS.c:.o}


all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(SRCS) $(OBJS) mandatory/philo.h
	cc -pthread -Wall -Wextra -Werror $(SRCS) -o $(NAME)

$(NAME_BONUS) : $(SRCS_BONUS) $(OBJS_BONUS) bonus/philo_bonus.h
	cc -pthread -Wall -Wextra -Werror $(SRCS_BONUS) -o $(NAME_BONUS)

fclean :
	rm -rf $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_BONUS)
clean : 
	rm -rf $(NAME) $(NAME_BONUS)
re : fclean all