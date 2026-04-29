
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//	fuzz testing the strcmp.

#define str_len 500
#define iterations 100000

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = malloc(str_len * sizeof(char));
	str1[str_len - 1] = 0;
	str2 = malloc(str_len * sizeof(char));
	str2[str_len - 1] = 0;

	int fd = open("/dev/random", 	O_RDONLY);

	int	i = 0;
	while (i < iterations)
	{
		read(fd, str1, str_len - 1);
		read(fd, str2, str_len - 1);
		int	ret_1 = ft_strcmp(str1, str2);
		int	ret_2 = ft_strcmp(str1, str2);
	
		if (ret_1 < 0)
			ret_1 = -1;
		if (ret_2 < 0)
			ret_2 = -1;
	
		if (ret_1 == 0)
			ret_1 = 0;
		if (ret_2 == 0)
			ret_2 = 0;
	
		if (ret_1 > 1)
			ret_1 = 1;
		if (ret_2 > 1)
			ret_2 = 1;
	
		if (ret_1 != ret_2)
			return (1);
		return (0);
	
	}
}

