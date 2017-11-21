#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "libft/libft.h"
#include "get_next_line.h"

// tgetnum
// tgetflag
// tgetstr

struct s_choice
{
	
};

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

void	start_highlight()
{
	char *command;
	char buf[30];
	char *ap = buf;

	command = tgetstr("so", &ap);
	ft_putstr(command);
}

void	end_highlight()
{
	char *command;
	char buf[30];
	char *ap = buf;

	command = tgetstr("se", &ap);
	ft_putstr(command);
}

void	set_terminal_raw()
{
	struct termios options;

	tcgetattr(STDIN_FILENO, &options);
	options.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &options);
}


void	init()
{
	create_terminal();
	set_terminal_raw();
}

void reset_input_mode(struct termios *saved)
{
	tcsetattr(STDIN_FILENO, TCSANOW, saved);
}

int main()
{
	struct termios saved;
	int bytes_read;
	char in_buffer[10];

	init();
	clear_screen();

	start_highlight();
	ft_putstr("Choice 1");
	end_highlight();
	move_cursor(0,1);
	ft_putstr("Choice 2");
	move_cursor(0,2);
	ft_putstr("Choice 3");
	move_cursor(0,3);

	char *s;
  	while (1)
  	{
  		bytes_read = read(STDIN_FILENO, &in_buffer, 1);
  		if (in_buffer[0] == '\033'){
  			read(STDIN_FILENO, &in_buffer, 1);
  			read(STDIN_FILENO, &in_buffer, 1);
  			if (in_buffer[0] == 'A'){
  				move_cursor(0, 1);
  				start_highlight();
  				move_cursor(1,1);
  				end_highlight();
  			}
  		}
  	}
	return (0);
}