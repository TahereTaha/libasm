
#include "libasm.h"
#include <stdio.h>

//	testing a empty string.

#define TEST_STR ""

int	main(void)
{
	if (ft_strlen(TEST_STR) != 0)
		return (1);
	return (0);
}


