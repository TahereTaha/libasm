
#include "libasm.h"
#include <stdio.h>
#include <string.h>

//	testing with a utf8 string.

#define TEST_STR "感激不尽 هل فاتك حدث ديبل الربيعي؟ اطلع على أحدث المستجدات حول الإصدارات المثيرة في مركز فعاليات الربيع الخاص بنا! 💂🏻👨🏻‍🦲 "

int	main(void)
{
	if (ft_strlen(TEST_STR) != strlen(TEST_STR))
		return (1);
	return (0);
}


