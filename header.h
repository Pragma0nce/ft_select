#ifndef HEADER_H
#define	HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "libft/libft.h"

typedef struct s_menu t_menu;

struct s_menu
{
	int cur_choice;
	int num_choices;
	int cursor_x;
	int cursor_y;

	char **choices;
};

void		display_menu(t_menu *menu);
void		clear_screen(void);
void		move_cursor(int hpos, int vpos);
void		menu_up(t_menu *menu);
void		menu_down(t_menu *menu);
void		start_highlight(void);
void		end_highlight(void);
t_menu		*create_menu(int n, char **argv);
void		display_menu(t_menu *menu);
void		create_terminal(void);
void		set_terminal_raw(void);
void		init(int argc, char **argv);
void		reset_input_mode(struct termios *saved);
void		check_key(char *key, t_menu *menu);
void		end_underline(void);
void		start_underline(void);
void		hide_cursor(void);
void		show_cursor(void);




#endif