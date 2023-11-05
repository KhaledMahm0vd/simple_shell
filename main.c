#include "main.h"

int main(int ac, char **argv){
	char *prompt = "(simple_shell) $ ";
	char *lnpointer;
	size_t n = 0;
	
	/* declaring void variables */
	(void)ac; (void)argv;
	
	printf("%s", prompt);
	getline(&lnpointer, &n, stdin);
	
	free(lnpointer);
	return (0);
}
