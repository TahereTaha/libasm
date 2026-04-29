
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	simple hello world test diferent.

#define	STR1 "hello world!!!"
#define	STR2 "goodbye nothingness..."

int	main(void)
{
	if (ft_strcmp(STR1, STR2) == strcmp(STR1, STR2))
		return (1);
	return (0);
}

