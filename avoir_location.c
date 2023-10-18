/*  avoir_location.c */

#include "shell.h"

char  *avoir_LOcation(char *commande)
{

    struct stat buff;
    if (stat(commande, &bufF) == 0)
{

	return (commande);

}

return (NULL);
}
