
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	large test.

#define SRCS_STR "hello world!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
#define DEST_STR "goodbye nothingness..."

int	main(void)
{
	char	srcs[4000] = SRCS_STR;
	char	dest[4000] = DEST_STR;

	if (!strcmp(srcs, dest))
		return (1);
	char	*ret = ft_strcpy(dest, srcs);
	if (ret != dest)
		return (1);
	if (strcmp(srcs, dest))
		return (1);
	if (strcmp(dest, SRCS_STR))
		return (1);
	return (0);
}


