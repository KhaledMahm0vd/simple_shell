#include "main.h"
/**
 * main - entry point
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char cmd[MAX_COM_LEN];

	while (1)
	{
	/* Display the prompt */
	printf("$> ");
	/* Read the user input */
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
		/* Handle end of file (Ctrl+D) */
		printf("\nExiting. Goodbye!\n");
		exit(0);
		}
		/* Remove the newline character from the end of the command */
		cmd[strcspn(cmd, "\n")] = '\0';
		/* Execute the command */
		if (access(cmd, X_OK) == 0)
		{
		/* Command found, execute it */
		system(cmd);
		}
		else
		{
		/* Command not found */
		fprintf(stderr, "Command not found: %s\n", cmd);
		}
	}
	return (0);
}
