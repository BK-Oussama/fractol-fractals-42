
#gcc main.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext libft/libft.a -lm

# Define compiler
CC = cc 

# Define CFLAGS (compiler flags)
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft   #-g -fsanitize=address

# Source code files
SRCs =  
Libft = libft/libft.a

# Executable name
NAME = fractol

# Main target (to build the executable)
all: $(NAME)

# How to build the executable
$(NAME): $(SRCs) $(Libft)
	$(CC) $(CFLAGS) $(SRCs) $(Libft) -o $(NAME)

$(Libft):
	make -s -C libft
	make bonus -s -C libft 
	
# Target to clean up object files
clean:
	rm -f $(NAME)
	make clean -C libft

# Target to clean up object files & the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

# Rebuild everything (clean first, then build)
re: fclean all
