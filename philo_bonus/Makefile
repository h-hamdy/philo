# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 04:42:20 by hhamdy            #+#    #+#              #
#    Updated: 2022/08/16 14:24:44 by hhamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc

CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=thread -g

NAME	=	philo_bonus

SRCS	=	philo_bonus.c \
			utils_bonus.c \
			fill_struct_bonus.c \
			routine_bonus.c \
			ft_usleep_bonus.c \

define HEADER_M
           __    _ __                       __                  
    ____  / /_  (_) /___  _________  ____  / /_  ___  __________
   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/
  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) 
 / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  
/_/                              /_/                            
endef
export HEADER_M

all:	bonus

bonus: $(NAME)

$(NAME) : $(SRCS)
	@ $(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@ echo "\033[0;32m$$HEADER_M\033[0m\n"
	@ echo "\033[1;32mPhilosophers has been compiled!\033[0m\n"

clean:
	@rm -rf $(OBGS)

fclean:	clean
	@rm -rf $(NAME)
	@echo "\n\033[0;31m</ EVERYTHING HAS BEEN DELETED! >\033[0m\n"

re:		fclean all

.PHONY:	all clean fclean re