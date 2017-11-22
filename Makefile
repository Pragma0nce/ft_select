CFLAGS=-Wall -Werror -Wextra
EXECUTABLE=ft_select
LDFLAGS=-ltermcap ./libft/libft.a
OBJECTS=main.o events.o termcaps.o menu.o terminal.o

all: ft_libft ft_select

ft_libft:
	$(MAKE) -C ./libft

ft_select: $(OBJECTS)
	gcc $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(CFLAGS)

main.o: main.c
	gcc -c main.c

events.o: events.c
	gcc -c events.c

termcaps.o: termcaps.c
	gcc -c termcaps.c

menu.o: menu.c
	gcc -c menu.c

terminal.o: terminal.c
	gcc -c terminal.c

.PHONY : clean
clean:
	rm $(OBJECTS) $(EXECUTABLE)