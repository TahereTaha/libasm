
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	simple hello world test diferent.

#define	STR1 "zello world!!!"
#define	STR2 "aoodbye nothingness..."

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

