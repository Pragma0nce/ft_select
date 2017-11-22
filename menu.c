#include "header.h"

t_select	*create_list(int n, char **array)
{
	int			i;
	t_select	*head;
	t_select	*list;
	t_select	*prev_link;

	i = 0;
	list = (t_select*)malloc(sizeof(t_select));
	prev_link = NULL;
	head = list;
	while (i < n)
	{
		list->value = ft_strdup(array[i]);
		list->prev = prev_link;
		if (i + 1 < n)
		{
			list->next = (t_select*)malloc(sizeof(t_select));
			prev_link = list;
			list = list->next;
		}
		i++;
	}
	list->next = head;
	head->prev = list;
	return (head);
}

t_menu	*create_menu(int n, char **argv)
{
	int i;
	int j;
	t_menu *menu;

	menu = (t_menu*)malloc(sizeof(menu));
	menu->num_choices = n;
	i = 0;
	menu->list = create_list(n, argv);
	menu->cur_choice = 0;
	menu->head = menu->list;
	return (menu);
}

void	display_menu(t_menu *menu)
{
	int i = 0;
	menu->list = menu->head;
	clear_screen();
	while (i < menu->num_choices)
	{
		if (i == menu->cur_choice)
		{
			start_underline();
			ft_putstr(menu->list->value);
			end_underline();
		}
		else
		{
			ft_putstr(menu->list->value);
		}
		ft_putstr("\n");
		menu->list = menu->list->next;
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

