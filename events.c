#include "header.h"

void	check_key(char *key, t_menu *menu)
{
	if (key[0] == '\033' && key[1] == 0)
	{
		show_cursor();
		exit(0);
	}
	else
	{
  		if (key[0] == 'A')//up
      {
  			menu_up(menu);
  		}
  		else if (key[0] == 'B')//down
  		{
  			menu_down(menu);
  		}
      else if (key[0] == 32)//spacebar
      {
        select_item(menu);
      } 
  	}
}