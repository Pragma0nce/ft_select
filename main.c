#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>

// tgetnum
// tgetflag
// tgetstr
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*create_terminal()
{
	char *buf;
	buf = (char*)malloc(sizeof(char) * 1024);
	tgetent(buf, getenv("TERM"));
	return (buf);
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

int main()
{
	char *term_desc;

	term_desc = create_terminal();

	ft_putstr("ayy");
	clear_screen();
	move_cursor(10, 10);
	ft_putstr("boo");
	return (0);
}