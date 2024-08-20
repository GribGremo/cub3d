# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 15:32:16 by sylabbe           #+#    #+#              #
#    Updated: 2024/08/20 17:06:09 by sylabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address

SRC_MDT_DIR = mdt/srcs

DEST_MDT_DIR = mdt/obj

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRC =	$(addprefix $(SRC_MDT_DIR)/, 	cub3d.c \
										debug.c \
										utils.c)


OBJECTS = $(SRC:$(SRC_MDT_DIR)/%.c=$(DEST_MDT_DIR)/%.o)

CC = cc

RM = rm -f

all: $(NAME)


$(NAME): $(OBJECTS)
	@${MAKE} -C ./Libft
	@echo "\033[0;32mLIBFT COMPILED\033[0m"
	@${CC} ${CFLAGS} $(OBJECTS) ./Libft/libft.a -o $(NAME) -lreadline
	@echo "\033[0;32mMANDATORY COMPILED\033[0m"


$(DEST_MDT_DIR)/%.o: $(SRC_MDT_DIR)/%.c | obj
	@$(CC) $(CFLAGS) -c $< -o $@ -g


obj:
	@mkdir -p $(DEST_MDT_DIR)

clean:
	@${MAKE} -C ./Libft fclean
	@$(RM) -r $(DEST_MDT_DIR) 
	@echo "\033[0;33mCLEAN OBJECTS\033[0m"

fclean: clean
	@$(RM) $(NAME) 
	@echo "\033[0;33mCLEAN EXEC\033[0m"

#re: fclean all
re:
	@${MAKE} fclean all;

MAKEFLAGS         += --no-print-directory

.PHONY: all clean fclean re bonus

