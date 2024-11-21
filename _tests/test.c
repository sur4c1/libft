#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>    /* for getopt_long; POSIX standard getopt is in unistd.h */
#include "../libft.h"

#ifdef FT
#define f(argc, argv, optstring) ft_getopt_long(argc, argv, optstring, NULL, NULL)
#else
#define f(argc, argv, optstring) getopt_long(argc, argv, optstring, NULL, NULL)
#define FT -1
#endif

void print(int argc, char**argv)
{
		int i = 0;
		printf("[ ");
		while (++i < argc)
				printf("%s ", argv[i]);
		printf("]\n");
}

int test(int argc, char**argv)
{
		int ret;

		ret = f(argc, argv, "abc:d:012");
		printf("ret value = %d, ret char = %c, optind = %d, optopt value = %d, optopt char = %c", ret, ret, optind, optopt, optopt);
		print(argc, argv);
		return ret;
}


int main (int argc, char **argv) {
	printf("FT = %d\n", FT);
	print(argc, argv);
	opterr = 0;
	while (test(argc, argv) != -1)
			;
	print(argc, argv);
	exit (0);
}
