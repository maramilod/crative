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
	pid_t pid;
	char *const arg[] = {NULL};
	char *lin = NULL;
	size_t l = 0;
	ssize_t r;
	int result;

	while(1)
	{
		printf("<3 ");
		r = getline(&lin, &l, stdin);
		if (r == -1)
			return (-1);
		result = same(lin, "/bin/ls");
		if (result == 0)
		{
			pid = fork();
			if (pid == 0)
				execve("/bin/ls", arg, NULL);
			else
				wait(NULL);
    		}
		else
		{
        		printf("str1 is less than str2\n");
    		}
			printf("%s", lin);
	}
	free(lin);
	printf("\n");
	return (0);
}
