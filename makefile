NAME = philo

SRC = src/main.c src/utils.c src/initializations.c src/routine.c

OBJ = ${SRC:%.c=%.o}

FLAGS =  -Wall -Wextra -Werror 

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
