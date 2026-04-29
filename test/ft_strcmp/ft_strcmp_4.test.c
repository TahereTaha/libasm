
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	one string shorter than the other.

#define	STR1 "hello world!!!"
#define	STR2 "hello"

int	main(void)
{
	int	ret_1 = ft_strcmp(STR1, STR2);
	int	ret_2 = ft_strcmp(STR1, STR2);

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

