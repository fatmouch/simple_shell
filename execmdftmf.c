/* execmdftm.c */
#include "shell.h"

void execmdftmf(char *commande)
{
    char *vrai_commande = avoir_LOcation(commande);

    if (vrai_commande)
	{
	const char *argv[] = {vrai_commande, NULL};
	if (execve(vrai_commande, argv, NULL) == -1)
{
	perror("execve");
	free(vrai_commande);
	exit(EXIT_FAILURE);
	}
	free(vrai_commande);
	}
else
	{
	tima_mhmd_print_function("Command not found\n");
    }
}

