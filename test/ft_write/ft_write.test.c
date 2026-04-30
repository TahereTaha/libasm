
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//	simple hello world test.

#define SRCS_STR "hello world!"

int	main(void)
{
	char	srcs[40] = SRCS_STR;
	char	dest[40];

	int	my_pipe[2];
   	int	p_ret = pipe(my_pipe);
	(void)p_ret;

	ssize_t	w_ret = write(my_pipe[1], srcs, strlen(srcs));
	int		w_errno = errno;
	(void)w_ret;
	(void)w_errno;

	ssize_t	r_ret = read(my_pipe[0], dest, strlen(srcs) + 1);
	int		r_errno = errno;
	(void)r_ret;
	(void)r_errno;

	if (strcmp(srcs, dest))
		return (1);
	return (0);
}


