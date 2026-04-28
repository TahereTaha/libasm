
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	simple hello world test.


int	main(void)
{
	char	srcs[40] = "hello world!!!";
	char	dest[40] = "goodbye nothingness...";

	if (!strcmp(srcs, dest))
		return (1);
	char	*ret = ft_strcpy(dest, srcs);
	if (ret != dest)
		return (1);
	if (strcmp(srcs, dest))
		return (1);
	return (0);
}


