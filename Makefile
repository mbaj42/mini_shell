# Kompilator i flagi
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

# Nazwa programu
NAME = shell

# Ścieżki katalogów
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = printf

# Pliki źródłowe i obiektowe
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Biblioteki
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Cel główny
all: $(NAME)

# Tworzenie pliku wykonywalnego
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(LDFLAGS)

# Kompilacja plików .c do .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Czyszczenie plików obiektowych
clean:
	rm -rf $(OBJ_DIR)

# Czyszczenie wszystkich plików
fclean: clean
	rm -f $(NAME)

# Odtworzenie projektu
re: fclean all

# Wspieranie bibliotek
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)
