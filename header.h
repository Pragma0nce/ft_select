#ifndef HEADER_H
#define	HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <termios.h>
#include "libft/libft.h"

typedef struct s_menu t_menu;

typedef struct s_select t_select;

void	display_menu(t_menu *menu);

struct s_menu
{
	int 		num_choices;
	int			cur_choice;
	int 		cursor_x;
	int 		cursor_y;
	t_select	*head;
	t_select 	*list;
};

struct s_select
{
	char		*value;
	int			is_selected;
	t_select	*prev;
	t_select	*next;
};

void		select_item(t_menu *menu);
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