#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>    /* for getopt_long; POSIX standard getopt is in unistd.h */
#include "../libft.h"

#ifdef FT
#define f(argc, argv, optstring) ft_getopt_long(argc, argv, optstring, NULL, NULL)
#define optind ft_optind
#define optopt ft_optopt
#define optarg ft_optarg
#define opterr ft_opterr
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

int	test(int argc, char**argv)
{
	static int i = 0;
	int ret;

	ret = f(argc, argv, "abc:d:012");
	printf("\n CALL %d\n", i++);
	printf("ret=%d", ret);
	if (ft_isprint(ret))
		printf(" (%c)", ret);
	else if (ret == -1)
		printf(" (EOF)");
	else
		printf(" (.)");
	printf("\n");
	printf("optind=%d\n", optind);
	printf("optopt=%d", optopt);
	if (ft_isprint(optopt))
		printf(" (%c)", optopt);
	else
		printf(" (.)");
	printf("\n");
	printf("optarg=%s\n", optarg);
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
