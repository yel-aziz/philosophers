NAME = philo

NAME_BONUS = philo_bonus

SRCS = mandatory/main.c mandatory/ft_atoi.c mandatory/timeSeter.c  mandatory/checker.c mandatory/destroy.c mandatory/parcing.c

SRCS_BONUS = bonus/init_bonus.c bonus/main_bonus.c bonus/ft_atoi.c 

OBJS = ${SRCS.c:.o}

OBJS_BONUS = ${SRCS.c:.o}

all : $(NAME)


$(NAME) : $(SRCS) $(OBJS) mandatory/philo.h
	@echo "\033[92mrunning...\033[0m"
	@cc -pthread -Wall -Wextra -Werror $(SRCS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(SRCS_BONUS) $(OBJS_BONUS) bonus/philo_bonus.h
	@echo "\033[92mrunning bonus...\033[0m"
	@cc -pthread -Wall -Wextra -Werror $(SRCS_BONUS) -o $(NAME_BONUS)

%.o : %.c
	@$(cc) $(FLAGS) -c $< -o $@

fclean :
	rm -rf $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_BONUS)
clean : 
	rm -rf $(NAME) $(NAME_BONUS)
re : fclean all
