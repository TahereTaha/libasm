
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	simple hello world test equal.

#define	STR1 "hello world!!!"
#define	STR2 "hello world!!!"

int	main(void)
{
	if (ft_strcmp(STR1, STR2) != strcmp(STR1, STR2))
		return (1);
	return (0);
}

