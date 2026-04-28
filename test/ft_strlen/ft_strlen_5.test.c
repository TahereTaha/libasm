
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//	fuzz testing with /dev/urandom

#define short_str_len 50
#define medium_str_len 200
#define large_str_len 100000

#define short_str_passes 100000
#define medium_str_passes 10000
#define large_str_passes 500

int	main(void)
{
	char	*short_str;
	char	*medium_str;
	char	*large_str;

	short_str = malloc(short_str_len * sizeof(char));
	short_str[short_str_len - 1] = 0;
	medium_str = malloc(medium_str_len * sizeof(char));
	medium_str[medium_str_len - 1] = 0;
	large_str = malloc(large_str_len * sizeof(char));
	large_str[large_str_len - 1] = 0;

	int fd = open("/dev/urandom", 	O_RDONLY);

	size_t	i;

	i = 0;
	while (i < short_str_passes)
	{
		read(fd, short_str, short_str_len - 1);
		if (ft_strlen(short_str) != strlen(short_str))
			return (1);
		i++;
	}
	i = 0;
	while (i < medium_str_passes)
	{
		read(fd, medium_str, medium_str_len - 1);
		if (ft_strlen(medium_str) != strlen(medium_str))
			return (1);
		i++;
	}
	i = 0;
	while (i < large_str_passes)
	{
		read(fd, large_str, large_str_len - 1);
		if (ft_strlen(large_str) != strlen(large_str))
			return (1);
		i++;
	}
		
	return (0);
}


