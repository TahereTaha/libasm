#pragma once

#include <aio.h>

//	Description:
//		calculates the length of a string pointed by str, 
//		excluding the terminating null byte ('\0').
//	Return:
//		It will return the number of bytes in the string 
//		pointed by str.
//	Undefined Behaviour:
//		any str that is not pointing at a valid c string will be undefined behaivour.

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *srcs);
int		ft_strcmp(char *str1, char *str2);




