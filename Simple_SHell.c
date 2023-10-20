#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;

	while (1)
	{
		getcommand = _getlin_commande();
		if (getcommand)
		{
			pathValue++;
			user_command = _get_tooKken(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!strng_cmpr(user_command[0], "exit")) && user_command[1] == NULL)
				_exit_ccomand(user_command, getcommand, _exit);
			if (!strng_cmpr(user_command[0], "env"))
				_getttenv(env);
			else
			{
				n = values_de_path(&user_command[0], env);
				_exit = _forkk_fuUn(user_command, av, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(getcommand);
	}
	return (_exit);
}
