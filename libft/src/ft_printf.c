#include "libft.h"

int	ft_printf(char const *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_dprintf(1, format, arg);
	va_end(arg);
	return (ret);
}
