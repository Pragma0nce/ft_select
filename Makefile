CFLAGS=-Wall -Werror -Wextra
EXECUTABLE=ft_select
LDFLAGS=-ltermcap ./libft/libft.a
OBJECTS=main.o get_next_line.o

all: ft_libft ft_select

ft_libft:
	$(MAKE) -C ./libft

ft_select: $(OBJECTS)
	gcc $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(CFLAGS)

main.o: main.c
	gcc -c main.c

get_next_line.o: get_next_line.c
	gcc -c get_next_line.c

.PHONY : clean
clean:
	rm $(OBJECTS) $(EXECUTABLE)