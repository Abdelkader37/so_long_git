NAME = so_long
SRCS = main.c
OBJS = $(SRCS:.c=.o)

All : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC)  -Imlx -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
