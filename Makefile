CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
ASAN_FLAGS		= -fsanitize=address -fno-omit-frame-pointer -Wno-format-security

NAME			= server client

all:
				$(CC) $(CFLAGS) $(ASAN_FLAGS) client.c ft_atoi.c -o client
			  	$(CC) $(CFLAGS) $(ASAN_FLAGS) server.c ft_printf.c -o server

clean:
				$(RM) $(NAME)

LEAKS = -g -fsanitize=leak
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -Wno-format-security
