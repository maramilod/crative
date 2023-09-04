#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - entry point
 * Return: always 0
 */
int main()
{
	FILE *fd;

	fd = fopen("testme.txt", "w");
	fprintf(fd, "%s", "HI MA_AM");
	fclose(fd);

	return (0);
}
