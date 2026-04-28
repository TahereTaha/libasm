
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	copy empty string.

#define SRCS_STR ""
#define DEST_STR "goodbye nothingness..."

int	main(void)
{
	char	srcs[40] = SRCS_STR;
	char	dest[40] = DEST_STR;

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


