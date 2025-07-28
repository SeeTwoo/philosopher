CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
DFLAGS = $(CFLAGS) -g3

SRC_DIR = src
SRC_FILES =	cleaners.c \
			delay.c \
			init_philosophers.c \
			lone_philo_runtime.c \
			main.c \
			monitor_threads.c \
			parsing.c \
			philo_runtime.c \
			phlog.c \
			start_threads.c \
			usage.c \
			wait_threads.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

NAME = philosopher 

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^

debug: fclean
	$(MAKE) CFLAGS="$(DFLAGS)" all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
