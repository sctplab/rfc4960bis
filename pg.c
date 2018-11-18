/*
 * This program is taken from https://tools.ietf.org/html/rfc1543#section-18
 * and has been slightly modernised.
 *  Remove n lines following any line that contains a form feed (^L).
 *  Usage:
 *      -n#     Number of lines to delete following each ^L (0 default).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Print rest of line, then delete next n lines. */
void
print_and_delete(int n)
{
	int c, cntr;

	while ((c = getchar()) != '\n')       /* finish current line */
		putchar(c);
	putchar('\n');                        /* write the last CR */
	putchar('\f');

	for (cntr = 0; cntr < n; cntr++)
		while ((c = getchar()) != '\n')
			if (c == EOF)
				exit(0);                        /* exit on EOF */
	putchar(c);                           /* write that last CR */
}

int
main(int argc, char *argv[])
{
	int c, nlines;

/* Process option (-nlines) */

	nlines = 0;
	while ((c = getopt(argc, argv, "n:N:")) != EOF)
		switch(c) {
		case 'n':
		case 'N':
			nlines = atoi(optarg);
			break;
		}
	/* READ AND PROCESS CHARS */
	while ((c = getchar()) != EOF)
		if (c == '\f')
			print_and_delete(nlines);
		else
			putchar(c);
	return (0);
}
