#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "libft/libft.h"

// tgetnum
// tgetflag
// tgetstr

void	create_terminal()
{
	char *buf;
	buf = (char*)malloc(sizeof(char) * 1024);
	tgetent(buf, getenv("TERM"));
	// return (buf);
}

void	clear_screen(void)
{
	char *command;
	char buf[30];
	char *ap = buf;

	command = tgetstr("cl", &ap);
	ft_putstr(command);
}

void	move_cursor(int hpos, int vpos)
{
	char *command;
	char buf[30];
	char *ap = buf;

	command = tgetstr("cm", &ap);
	ft_putstr(tgoto(command, hpos, vpos));
}

void	set_terminal_raw()
{
	struct termios options;
	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 4;
}

void	init()
{
	create_terminal();
	set_terminal_raw();
}

int main()
{
	init();

	ft_putstr("ayy");
	clear_screen();
	move_cursor(10, 10);
	ft_putstr("boo");
	move_cursor(10, 11);
	ft_putstr("boo");
	return (0);
}