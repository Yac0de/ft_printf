# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:22:15 by ymeziane          #+#    #+#              #
#    Updated: 2023/10/25 11:22:15 by ymeziane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TEST_FILE =			test.c
# TEST_EXEC =			test.out

NAME =				libftprintf.a
CC =				cc
FLAGS =				-Wall -Wextra -Werror
INCLUDES =			-I./inc -I./libft/inc

LIBFT =				libft/libft.a

SRC_DIR =			src
BONUS_SRC_DIR =		src_bonus
OBJ_DIR = 			obj
BONUS_OBJ_DIR =		obj_bonus

SRC_FILES =        handle_percent printf handle_char \
                   handle_hex handle_int handle_pointer handle_string handle_unsigned process_string

BONUS_SRC_FILES =  handle_percent printf handle_char handle_flags \
                   handle_hex handle_hex_utils handle_int \
                   handle_int_utils handle_pointer \
                   handle_string handle_unsigned process_string

SRC =              $(addprefix $(SRC_DIR)/ft_, $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC =        $(addprefix $(BONUS_SRC_DIR)/ft_, $(addsuffix _bonus.c, $(BONUS_SRC_FILES)))
OBJ =              $(addprefix $(OBJ_DIR)/ft_, $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ =        $(addprefix $(BONUS_OBJ_DIR)/ft_, $(addsuffix _bonus.o, $(BONUS_SRC_FILES)))

GREEN = 			\033[0;32m
YELLOW = 			\033[0;33m
CYAN = 				\033[0;36m
RESET = 			\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)Compiling $(NAME) from the following files:$(RESET)"
	@echo "$(SRC)"
	@$(MAKE) -C libft
	@cp $(LIBFT) $@
	@ar rcs $@ $(OBJ)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Compiling $< into $@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $< successfully.$(RESET)"

$(BONUS_OBJ_DIR)/%_bonus.o: $(BONUS_SRC_DIR)/%_bonus.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@echo "$(GREEN)Compiled $< into $@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled $< successfully.$(RESET)"

bonus: $(BONUS_OBJ) .bonus_done

.bonus_done: $(BONUS_OBJ)
	@echo "$(CYAN)Adding the following bonus objects to $(NAME):$(RESET)"
	@echo "$(BONUS_OBJ)"
	@$(MAKE) -C libft
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@touch .bonus_done
	@echo "$(GREEN)Bonus objects added successfully!$(RESET)"

clean:
	@echo "$(CYAN)Cleaning object files and directories...$(RESET)"
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) .bonus_done
	@$(MAKE) clean -C libft
	@echo "$(YELLOW)Object files cleaned.$(RESET)"

fclean: clean
	@echo "$(CYAN)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft
	@echo "$(GREEN)Full clean completed successfully!$(RESET)"

re: fclean all

# test: $(NAME)
# 	@echo "$(CYAN)Compiling test program...$(RESET)"
# 	@$(CC) $(FLAGS) $(INCLUDES) $(TEST_FILE) -L. -lftprintf -o $(TEST_EXEC)
# 	@echo "$(CYAN)Running test program...$(RESET)"
# 	@./$(TEST_EXEC)

.PHONY: all clean fclean re bonus test
