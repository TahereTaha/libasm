
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

//	forsing the error of EBADF.

int	main(void)
{
	signal(SIGPIPE, SIG_IGN);
	int	my_pipe[2];
	pipe(my_pipe);
	close(my_pipe[0]);
	ssize_t	my_ret = ft_write(my_pipe[1], "hello", 3);
	int		my_errno = errno;

	int	original_pipe[2];
	pipe(original_pipe);
	close(original_pipe[0]);
	ssize_t	original_ret = write(original_pipe[1], "hello", 3);
	int		original_errno = errno;

	if (my_ret != original_ret)
		return (1);
	if (my_errno != original_errno)
		return (1);
	return (0);
}


