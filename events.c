#include "header.h"

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