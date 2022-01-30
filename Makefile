INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = bin/
LIBFT_DIR = libft/
                                                                                                                          
SRCS = main.c utils.c parse_args.c operation.c operation2.c sort.c cost.c ops.c median.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

NAME = push_swap

CFLAGS = -Werror -Wextra -Wall -g
LINKS = -L$(LIBFT_DIR) -lft
INCPATH = -I$(INC_DIR) -I$(LIBFT_DIR)includes/

LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	gcc $(OBJS) $(LINKS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) $(INCPATH) -c $< -o $@

$(OBJ_DIR): 
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	
libclean:
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) 

bonus: all

re: fclean all

.PHONY: all clean fclean re libft libclean 
