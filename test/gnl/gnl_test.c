#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_CREAT);
	}
	if (fd < 0)
	{
		perror("Open");
		exit(1);
	}
	while ((str = ft_gnl(fd)))
	{
		printf(">%s<\n", str);
		free(str);
	}
	close(fd);
}
