
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//	fuzz testing with /dev/urandom

#define	str_len 5000

#define str_passes 1000000

int	main(void)
{
	char	*srcs;
	char	*dest;
	char	*old_dest;

	srcs = malloc(str_len * sizeof(char));
	srcs[str_len - 1] = 0;
	dest = malloc(str_len * sizeof(char));
	dest[str_len - 1] = 0;
	old_dest = malloc(str_len * sizeof(char));
	old_dest[str_len - 1] = 0;

	int fd = open("/dev/urandom", 	O_RDONLY);

	size_t	i;

	i = 0;
	while (i < str_passes)
	{
		read(fd, srcs, str_len - 1);
		old_dest = strcpy(old_dest, dest);
		char	*ret = ft_strcpy(dest, srcs);
		if (ret != dest)
			return (1);
		if (strcmp(srcs, dest))
			return (1);
		if (!strcmp(dest, old_dest))
			return (1);
		i++;
	}
	return (0);
}


