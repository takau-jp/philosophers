# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 09:06:59 by stanaka2          #+#    #+#              #
#    Updated: 2026/02/02 16:51:22 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#         Phony Rules        #
# -------------------------- #

.PHONY: all clean fclean re norm debug asan

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #

NAME = philo_bonus

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CC				= cc
CFLAGS			= -Wall -Werror -Wextra

ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
CFLAGS += -g -fsanitize=address
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CFLAGS += -g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR	= include
INCLUDE		= -I $(INCLUDE_DIR)

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS	=	src \
				$(addprefix src/, \
					argument_parsing argument_parsing/utils \
					cleanup cleanup/utils \
					dining_philosophers_simulation dining_philosophers_simulation/utils \
					error \
					initialization initialization/utils \
					utils utils/libft\
				)


# -------------------------- #
#        Source Files        #
# -------------------------- #

SRCS	=	main.c

# argument_parsing
SRCS	+=	parse_arguments.c \
			is_int.c

# error
SRCS	+=	print_error_log.c

# utils
SRCS	+=	create_name.c \
			ft_abs_ulong.c  ft_calloc.c   ft_isspace.c     ft_putstr_fd.c  ft_strlen.c \
			ft_atoi.c       ft_isdigit.c  ft_putendl_fd.c  ft_strcpy.c

# initialization
SRCS	+=	initialize.c \
			initialize_philos.c  initialize_simulation.c

# dining_philosophers_simulation
SRCS	+=	death_monitor_routine.c      philo_routine.c		eat_count_monitor_routine.c  simulate_dining_philosophers.c  waiter_routine.c \
			eating.c  get_timestamp.c  has_time_elapsed.c  logger.c  sleeping.c  smart_sleep.c  thinking.c

# cleanup
SRCS	+=	cleanup.c  clear_for_child_process.c \
			cleanup_philos.c  cleanup_simulation.c  clear_philos.c  clear_simulation.c


# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        Main Targets        #
# -------------------------- #

all	: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo -e "[PHILO_BONUS] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan:	$(NAME)

debug:  $(NAME)

sbuild:
	@$(MAKE) fclean
	scan-build make
	@$(MAKE) fclean

norm:
	@norminette -o src $(INCLUDE_DIR) | grep Error || true

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[PHILO_BONUS] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[PHILO_BONUS] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[PHILO_BONUS] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

re:	fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(DEPS)
