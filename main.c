#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *fl_cmd = NULL, *cp_cmd = NULL;
	size_t n = 0;
	ssize_t no_characters_read;
	char *tok;
	const char *delim = "\n";
	char **argv;
	int k = 0;
	int no_tok = 0;
	/* display a prompt for user to input something */
	printf("$ ");
	/* get input string */
	no_characters_read = getline(&fl_cmd, &n, stdin);
	/* allocating some space for characters read */
	cp_cmd = malloc(sizeof(char) * no_characters_read);
	if (cp_cmd == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	/* copying typed command */
	strcpy(cp_cmd, fl_cmd);
	/* checking getline response */
	if (no_characters_read == -1)
	{
		printf("Exiting shell ... \n");
		return (-1);
	}
	else
	{
		/* string full command into words array */
		tok = strtok(fl_cmd, delim);
		/* memory allocation for arguments storing */
		while (tok != NULL)
		{
			no_tok++;
			tok = strtok(NULL, delim);
		}
		no_tok++;
		/* allocating memory for pointer */
		argv = malloc(sizeof(char *) * no_tok);
		tok = strtok(cp_cmd, delim);
		for (k = 0; tok != NULL; k++)
		{
			argv[k] = malloc(sizeof(char) * strlen(tok));
			strcpy(argv[k], tok);
			tok = strtok(NULL, delim);
		}
		argv[k] = NULL;
		free(argv);
		free(fl_cmd);
		free(cp_cmd);
	}
	return (0);
}
