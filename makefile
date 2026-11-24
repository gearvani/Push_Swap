# Name des ausführbaren Programms
NAME = push_swap

# Compiler und Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Quell- und Objektdateien
SRCS = main.c error.c init.c utils.c cleanup.c more_operations.c operations.c selection_sort.c bubble_sort.c

OBJS = $(SRCS:.c=.o)

# Pfad zu libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# Regeln
all: $(NAME)

# Erstellen des ausführbaren Programms
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Kompilieren der libft, nur wenn libft.a nicht existiert
$(LIBFT):
	make -C $(LIBFT_DIR)

# Erstellen der Objektdateien
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Aufräumen der Objektdateien
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Aufräumen der Objektdateien und der ausführbaren Datei
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Alles neu erstellen
re: fclean all

.PHONY: all clean fclean re