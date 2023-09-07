#include "main.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int same(const char *w, char *m)
{
        int a = 0, b = 0,i = 0;

        if (w == NULL || m == NULL)
                return (-1);
        while (w[a])
                a++;
        while (m[b])
                b++;
       a--; 
        if (a == b)
        {
                while (w[i] == m[i] && w[i] != '\0' && m[i] != '\0')
                        i++;
        }
        else
                return (-1);
        if ( i == a && i == b)
                return (0);

        return (-1);
}
/**
 */

int main(int argc, char **argv)
{
	char *test[] = {"/bin/ls", "./ppid", NULL};
	pid_t pid;
	char *const arg[] = {NULL};
	char *lin = NULL;
	size_t l = 0;
	ssize_t r;
	int i, j = 0;

	(void)argv;
	if (argc == 1)
	while(1)
	{
		printf("<3 ");
		r = getline(&lin, &l, stdin);
		if (r == EOF)
		{
			printf("\n");
			return (-1);
		}
		if ((same(lin, "exit") == 0))
				return (0);
		for (i = 0; test[i] != NULL; i++)
		{
			if (same(lin, test[i]) == 0)
			{
				pid = fork();
				 if (pid == 0)
				 {
                                	execve(test[i], arg, NULL);
				 }
                        	else if (pid > 0)
				{
                                	wait(NULL);
					j++;
				}
			}
                }
		if (j == 0)
		{
        		printf("str1 is less than str2\n");
    		}
	}
	free(lin);
	return (0);
}
