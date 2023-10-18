/* execmdftm.c */
#include "shell.h"

void execmdftmf(char *commande)
{
    char *vrai_commande = avoir_LOcation(commande);

    if (vrai_commande)
	{
	char *argv[2];
argv[0] = vrai_commande;
argv[1] = NULL;

	if (execve(vrai_commande, (char *const *)argv, NULL) == -1)
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

