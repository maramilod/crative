#include <stdlib.h>
#include <stdio.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    int character;
    size_t i = 0;

    /* Allocate initial buffer if needed */
    if (*lineptr == NULL) {
        *n = 16;  /* Initial buffer size */
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;  /* Error allocating memory */
        }
    }

    /* Read characters until newline or EOF */
    while ((character = getc(stream)) != EOF) {
        char *temp;

        /* Resize buffer if needed */
        if (i >= *n - 1) {
            *n += 16;  /* Incremental buffer size */
            temp = (char *)realloc(*lineptr, *n);
            if (temp == NULL) {
                return -1;  /* Error reallocating memory */
            }
            *lineptr = temp;
        }

        /* Store character in buffer */
        (*lineptr)[i++] = character;

        /* Break loop if newline is encountered */
        if (character == '\n') {
            break;
        }
    }

    /* Terminate the string */
    (*lineptr)[i] = '\0';

    /* Return the number of characters read */
    return i;
}

