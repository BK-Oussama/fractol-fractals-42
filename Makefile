
# Define compiler
CC = cc 

# Define CFLAGS (compiler flags)
CFLAGS =  -Wall -Wextra -Werror -O3 -I. -Ilibft   #-g -fsanitize=address

# Source code files
SRCs =  fractol.c events.c parsing.c draw_julia.c draw_mandelbrot.c utilis.c render_utilis.c
Libft = libft/libft.a

# Executable name
NAME = fractol

# Main target (to build the executable)
all: $(NAME)

# How to build the executable
$(NAME): $(SRCs) $(Libft)
	$(CC) $(CFLAGS) $(SRCs) $(Libft) -o $(NAME) -Lminilibx-linux -lmlx -lXext -lX11 -lm

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
