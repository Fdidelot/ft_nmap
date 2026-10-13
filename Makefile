NAME    = ft_nmap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I include

SRC_DIR = src
OBJ_DIR = obj

SRCS    = main.c help.c ports.c
OBJS    = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS    = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re