#include "shell.h"

int main(void)
{
	const char *PromPt = "(MED_tim's_shell) $ ";
	char *LinE = NULL;
	size_t len = 0;
	ssize_t NcHars_riid;
	const char *Delim = " \n";
    while (1)
    {
	tima_mhmd_print_function(PromPt);
	NcHars_riid = getline(&LinE, &len, stdin);

	if (NcHars_riid == -1)
	{
	tima_mhmd_print_function("Exiting shell....\n");
	free(LinE);
	exit(0);
	}

	/* Parse the input line into tokens */
	char *tOkEn = strtok(LinE, Delim);

	if (tOkEn != NULL)
	{
	execmdftm(tOkEn);
	}
	}

	free(LinE); /* Corrected variable name to match the declaration */
	return (0);
}
