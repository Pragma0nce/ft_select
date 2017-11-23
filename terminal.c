#include "header.h"

void	create_terminal(void)
{
	char *buf;
	buf = (char*)malloc(sizeof(char) * 1024);
	tgetent(buf, getenv("TERM"));
	// return (buf);
}


void	set_terminal_raw(void)
{
	struct termios options;

	tcgetattr(STDIN_FILENO, &options);
	options.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &options);
}

void reset_input_mode(struct termios *saved)
{
	tcsetattr(STDIN_FILENO, TCSANOW, saved);
}