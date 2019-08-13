NAME = ft_ssl_md5
FLAGS = -Wall -Wextra -Werror
CC = gcc

GIT_LIB = https://github.com/shfranc/libft
PATH_LIB = libft
LIB = libft.a

INCS = incs $(PATH_LIB)/includes

PATH_SRCS = srcs
SRCS = $(addprefix $(PATH_SRCS)/,\
	main.c \
	)

PATH_OBJS = objs
OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
CYAN = \033[01;36m
WHITE = \033[01;37m
RESET = \033[00m

all: $(PATH_LIB) $(NAME)

$(NAME): $(PATH_LIB)/$(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "$(GREEN)$@:$(RESET) OK"

$(PATH_LIB):
	@if [ ! -d $(PATH_LIB) ] ; then \
		git clone $(GIT_LIB) $(PATH_LIB); \
	fi

$(PATH_LIB)/$(LIB):
	@make -C $(PATH_LIB)

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(INCS)
	@test -d $(PATH_OBJS) || mkdir $(PATH_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ $(addprefix -I , $(INCS))
	@echo "$(YELLOW)compil:$(RESET) $@"

norm:
	@norminette $(PATH_SRCS) incs

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PATH_OBJS)
	@echo "$(BLUE)clean:$(RESET) $(PATH_OBJS)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BLUE)clean:$(RESET) $(NAME)"

fclean_lib:
	@make fclean -C $(PATH_LIB)

fclean_all: fclean_lib fclean

re_with_lib: fclean_all all

re: fclean all
