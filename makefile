NAME = philo

SRC = main.c utils.c initializations.c routine.c

OBJ = ${SRC:%.c=%.o}

FLAGS =  -Wall -Wextra -Werror -fsanitize=thread 

%.o:%.c
		cc $(FLAGS)  -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf  $(NAME) 
re : fclean all
