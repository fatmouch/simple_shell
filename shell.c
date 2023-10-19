#include "shell.h"

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		print_string("\n#cisfun$ ");
	}
}

void handle_EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_string("\n");
			free(buff);
		}
		exit(0);
	}
}

void check_isatty(void)
{
	if (isatty(STDIN_FILENO))
		print_string("#cisfun$ ");
}

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **args;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		check_isatty();
		len = getline(&buff, &size, stdin);
		handle_EOF(len, buff);
		args = split_string(buff, " \n");
		if (!args || !args[0])
			execute_command(args);
		else
		{
			value = get_env_var("PATH");
			head = create_path_list(value);
			pathname = get_executable_path(args[0], head);
			f = check_build(args);
			if (f)
			{
				free(buff);
				f(args);
			}
			else if (!pathname)
				execute_command(args);
			else if (pathname)
			{
				free(args[0]);
				args[0] = pathname;
				execute_command(args);
			}
		}
	}
	free_list(head);
	free_args(args);
	free(buff);
	return (0);
}
