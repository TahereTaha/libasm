
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//	forsing the error of EBADF.

int	main(void)
{
	char	my_buff[1024];
	ssize_t	my_ret = ft_read(42, my_buff, 42);
	int		my_errno = errno;

	char	original_buff[1024];
	ssize_t	original_ret = write(42, original_buff, 42);
	int		original_errno = errno;

	if (my_ret != original_ret)
		return (1);
	if (my_errno != original_errno)
		return (1);
	return (0);
}


