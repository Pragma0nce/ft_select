#include "header.h"

t_select	*create_list(int n, char **array)
{
	int			i;
	t_select	*head;
	t_select	*list;
	t_select	*prev_link;

	i = 1;
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

void	display_usage(void)
{
	ft_putstr("Please supply arguments\n");
	ft_putstr("Usage: ./ft_select [argument 1] [argument 2] [argument n] ...\n");
}

t_menu	*create_menu(int n, char **argv)
{
	int j;
	t_menu *menu;

	if (n < 2)
	{
		display_usage();
		exit(1);
	}
	menu = (t_menu*)malloc(sizeof(menu));
	menu->num_choices = n - 1;
	menu->list = create_list(n, argv);
	menu->cur_choice = 0;
	menu->head = menu->list;
	return (menu);
}

void	print_underline(t_menu *menu)
{
	
	if (menu->list->is_selected)
	{
		start_underline();
		start_highlight();
		ft_putstr(menu->list->value);
		end_underline();
		end_highlight();
	}
	else
	{
		start_underline();
		ft_putstr(menu->list->value);
		end_underline();
	}
}

void	print_selected(t_menu *menu)
{
		start_highlight();
		ft_putstr(menu->list->value);
		end_highlight();
}

void	display_menu(t_menu *menu)
{
	int i = 0;
	t_menu *itt;

	itt = menu;
	itt->list = itt->head;
	clear_screen();
	while (i < itt->num_choices)
	{
		if (i == itt->cur_choice)
		{
			print_underline(itt);	
		}
		else if (itt->list->is_selected)
		{
			print_selected(itt);
		}
		else
			ft_putstr(itt->list->value);
		ft_putstr("\n");
		itt->list = itt->list->next;
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

void	select_item(t_menu *menu)
{
	int			index;
	int			count;
	t_menu		*itt;

	count = 0;
	itt = menu;
	index = itt->cur_choice;
	while (count != index)
	{
		count++;
		itt->list = itt->list->next;
	}
	if (itt->list->is_selected == 1)
		itt->list->is_selected = 0;
	else
		itt->list->is_selected = 1;
	display_menu(menu);
 }
