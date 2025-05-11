#include "libft.h"

void	flush_buffer(t_pfvars *pf)
{
	write(pf->fd, pf->buff, pf->current_size);
	pf->ret_val += pf->current_size;
	pf->current_size = 0;
}

int	buffer_is_full(t_pfvars *pf)
{
	va_copy(pf->arg_cpy, pf->arg);
	if (*(pf->format) != '%')
		pf->piece_size = ft_strcspn(pf->format, "%");
	else if (pf->format[1] == 's')
		pf->piece_size = ft_strlen(va_arg(pf->arg_cpy, char *));
	else if (pf->format[1] == 'd')
		pf->piece_size = nb_len(va_arg(pf->arg_cpy, int));
	va_end(pf->arg_cpy);
	return ((pf->current_size + pf->piece_size) > 1024);
}

void	fill_buffer(t_pfvars *pf)
{
	if (*(pf->format) != '%')
		regular_format(pf);
	else
		parse_specifier(pf);
}
