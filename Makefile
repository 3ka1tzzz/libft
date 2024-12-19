# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 10:47:21 by elopez-u          #+#    #+#              #
#    Updated: 2024/10/21 15:41:52 by elopez-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I .

# Source files
SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_split.c\
	  ft_strchr.c\
	  ft_strdup.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlcpy.c\
	  ft_strlen.c\
	  ft_strmapi.c\
	  ft_strncmp.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strtrim.c\
	  ft_substr.c\
	  ft_tolower.c\
	  ft_toupper.c

# Bonus files
BONUS = ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstsize_bonus.c

# Object files
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# Default target, compiles only core files
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule for bonus compilation
bonus: $(NAME) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Compile .c files into .o files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Clean object files and library
fclean: clean
	rm -f $(NAME)

# Recreate the library
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
