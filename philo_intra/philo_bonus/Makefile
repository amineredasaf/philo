NAME = philo_bonus
CC = CC -Wall -Werror -Wextra

SRS = main.c parsing.c excu.c init.c\

PAR = ./parsing/to_string.c ./parsing/check_char.c\
		./parsing/to_splitted.c ./parsing/to_int.c\
		./parsing/check_data.c

UTI =  ./utils/ft_error.c ./utils/ft_join.c \
		./utils/ft_putstr.c ./utils/ft_strdup.c \
		./utils/ft_strlen.c ./utils/ft_split.c \
		./utils/ft_atoi.c ./utils/print_state.c \
		./utils/resting.c \

#delete $(OTH)
FILES = $(SRS) $(PAR) $(UTI)

OBJ = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $^ -o $@
clean:
	rm $(OBJ)
fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
re: fclean $(NAME)