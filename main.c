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

typedef struct s_menu t_menu;

void	display_menu(t_menu *menu);

struct s_menu
{
	int cur_choice;
	int num_choices;
	int cursor_x;
	int cursor_y;

	char **choices;
};

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

void	menu_up(t_menu *menu)
{
	// ft_putstr("\033[A");
	// menu->cursor_y -=1;
	if (menu->cur_choice >= 1){
		menu->cur_choice -=1;
		display_menu(menu);
	}
}

void	menu_down(t_menu *menu)
{
	// ft_putstr("\033[B");
	// menu->cursor_y += 1;
	if (menu->cur_choice < menu->num_choices){
		menu->cur_choice +=1;
		display_menu(menu);
	}
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

t_menu	*create_menu(int n, char **argv)
{
	int i;
	int j;
	t_menu *menu;

	menu = (t_menu*)malloc(sizeof(menu));
	menu->choices = (char**)malloc(sizeof(char*) * n);
	menu->num_choices = n;
	menu->cur_choice = 0;
	i = 0;
	while (i < n)
	{
		menu->choices[i] = ft_strdup(argv[i]);
		i++;
	}

	return (menu);
}

void	display_menu(t_menu *menu)
{
	int i = 0;

	clear_screen();
	menu->cursor_x = 0;
	menu->cursor_y = 0;
	while (i < menu->num_choices)
	{
		if (i == menu->cur_choice)
			start_highlight();
		ft_putstr(menu->choices[i]);
		ft_putstr("\n");
		if (i == menu->cur_choice)
			end_highlight();
		// menu_down(menu);
		i++;
	}
}

void	create_terminal()
{
	char *buf;
	buf = (char*)malloc(sizeof(char) * 1024);
	tgetent(buf, getenv("TERM"));
	// return (buf);
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


void	init(int argc, char **argv)
{
	create_terminal();
	set_terminal_raw();
}

void reset_input_mode(struct termios *saved)
{
	tcsetattr(STDIN_FILENO, TCSANOW, saved);
}


void	check_key(char *key, t_menu *menu)
{
	if (key[0] == '\033')
	{
  		read(STDIN_FILENO, key, 1);
  		read(STDIN_FILENO, key, 1);
  		if (key[0] == 'A'){
  			menu_up(menu);
  		}
  		else if (key[0] == 'B')
  		{
  			menu_down(menu);
  		}
  	}
}

int main(int argc, char **argv)
{
	struct termios saved;
	int bytes_read;
	char in_buffer[10];
	t_menu	*menu;

	init(argc, argv);
	menu = create_menu(argc,argv);
	clear_screen();

	display_menu(menu);
	// start_highlight();
	// ft_putstr("Choice 1");
	// end_highlight();
	// move_cursor(0,1);
	// ft_putstr("Choice 2");
	// move_cursor(0,2);
	// ft_putstr("Choice 3");
	// move_cursor(0,3);

	char *s;
  	while (1)
  	{
  		bytes_read = read(STDIN_FILENO, &in_buffer, 1);
  		check_key(in_buffer, menu);
  	}
	return (0);
}