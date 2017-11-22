#include "header.h"

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
			start_underline();
		ft_putstr(menu->choices[i]);
		if (i == menu->cur_choice)
			end_underline();
		ft_putstr("\n");
		// menu_down(menu);
		i++;
	}
}

void	menu_up(t_menu *menu)
{
	// ft_putstr("\033[A");
	// menu->cursor_y -=1;
	if (menu->cur_choice <= 0)
		menu->cur_choice = menu->num_choices;
	menu->cur_choice -=1;
	display_menu(menu);
}

void	menu_down(t_menu *menu)
{
	// ft_putstr("\033[B");
	// menu->cursor_y += 1;
	if (menu->cur_choice >= menu->num_choices - 1)
		menu->cur_choice = -1;

	menu->cur_choice +=1;
	display_menu(menu);
}

