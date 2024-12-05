# Kompilator i flagi
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

# Nazwa programu
NAME = shell

# Pliki źródłowe
SRC = shell.c prompt.c user_input.c tokens.c tokenize_input.c valid_input.c error_handler.c
OBJ = $(SRC:.c=.o)

# Biblioteki
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

# Cel główny
all: $(NAME)

# Tworzenie pliku wykonywalnego
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(LDFLAGS)

# Kompilacja plików .c do .o
%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych
clean:
	rm -f $(OBJ)

# Czyszczenie wszystkich plików
fclean: clean
	rm -f $(NAME)

# Odtworzenie projektu
re: fclean all

# Wspieranie bibliotek
$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf
