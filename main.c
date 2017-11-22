#include "header.h"

// tgetnum
// tgetflag
// tgetstr

void	init(int argc, char **argv)
{
	create_terminal();
	set_terminal_raw();
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
	hide_cursor();

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