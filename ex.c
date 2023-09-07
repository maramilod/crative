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
int main(void)
{
	pid_t pid = 1;
	int i = -1;
	char *const arg[] = {NULL};
	char *line = NULL;
	const char *w = NULL;
	size_t li = 0;
        ssize_t	read;

	while (1)
	{
		if (pid != 0)
		{
			printf("$ ");
			read =  my_getline(&line, &li, stdin);
			if (read == EOF)
			{
				printf("\n");
				free(line);
				return (0);
			}
			else
			{
				w = strtok(line, " ");
				i = same(w, "/bin/ls");
				if (i != 0)
			 		printf("./shell: No such file or directory\n");

				if (i == 0)
        		        {
					wait(NULL);
					pid = fork();
					if (pid == 0)
					{
                                		execve("/bin/ls", arg, NULL);
				  	}
					i = -1;
				}
			}
		}
	}
	free(line);
	return (0);
}
