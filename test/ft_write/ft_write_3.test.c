
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//	forsing the error of EBADF.

int	main(void)
{
	ssize_t	my_ret = ft_write(42, "hello", 3);
	int		my_errno = errno;

	ssize_t	original_ret = write(42, "hello", 3);
	int		original_errno = errno;

	if (my_ret != original_ret)
		return (1);
	if (my_errno != original_errno)
		return (1);
	return (0);
}


