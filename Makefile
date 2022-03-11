CC				= gcc
RM				= rm -f
LIBFT			= libft
INC				= includes
LIBS			= -L$(LIBFT) -lft -I$(LIBFT)
HEADERS			= -I$(INC)
CFLAGS			= -Wall -Wextra -Werror $(LIBS) $(HEADERS)
ASAN_FLAGS		= -fsanitize=address -fno-omit-frame-pointer -Wno-format-security

NAME			= server client

all:
				@make -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(ASAN_FLAGS) client.c -o client
			  	@$(CC) $(CFLAGS) $(ASAN_FLAGS) server.c -o server
				@echo Ready to go
				@echo 
				@echo 

clean:
				@make fclean -s -C $(LIBFT)
				@$(RM) $(NAME)
fclean: clean

re: clean all
