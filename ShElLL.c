#include "shell.h"

int main(int ac, char **argv)
{
    const char *PromPt = "(MED_tim's_shell) $ ";
    const char *Delim = " \n";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_rid;
    int num_tokens = 0;
    char *token;
    int i;
    char *token = strtok(lineptr, Delim);

    /* declaring void variables */
    (void)ac;

    /* Create a loop for the shell's PromPt */
    while (1)
{
	tima_mhmd_print_function(PromPt);
	nchars_rid = getline(&lineptr, &n, stdin);
	/* check if the getline function failed or reached EOF or user use CTRL + D */
	if (nchars_rid == -1)
	{
	tima_mhmd_print_function("Exiting shell....\n");
	return (-1);
	}

	/* allocate space for a copy of the lineptr */
	lineptr_copy = malloc(sizeof(char) * nchars_rid);
	if (lineptr_copy == NULL)
	{
	perror("tsh: memory allocation error");
	return (-1);
	}
	/* copy lineptr to lineptr_copy */
	strcpy(lineptr_copy, lineptr);

	/********** split the string (lineptr) into an array of words ********/
	/* calculate the total number of tokens */
	token = strtok(lineptr, Delim);

	while (token != NULL)
	{
	num_tokens++;
	token = strtok(NULL, Delim);
	}
	num_tokens++;

	/* Allocate space to hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens);
	/* Store each token in the argv array */
	token = strtok(lineptr_copy, Delim);

	for (i = 0; token != NULL; i++)
	{
	argv[i] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[i], token);
	token = strtok(NULL, Delim);
	}
	argv[i] = NULL;

	/* execute the command */
	execmdftmf(PromPt);

	}


	/* free up allocated memory */
	free(lineptr_copy);
	free(lineptr);
	return (0);
	

	const char *PromPt = "(MED_tim's_shell) $ ";
	char *LinE = NULL;
	size_t len = 0;
	ssize_t NcHars_riid;
	const char *Delim = " \n";
	char *tOkEn;
	tOkEn = strtok(LinE, Delim);
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

	if (tOkEn != NULL)
	{
	execmdftmf(tOkEn);
	}
	}

	free(LinE); /* Corrected variable name to match the declaration */
	return (0);
}
