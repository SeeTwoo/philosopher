#include "libft.h"

void	regular_format(t_pfvars *pf)
{
	size_t	offset;

	offset = ft_strcspn(pf->format, "%");
	ft_memcpy(&(pf->buff)[pf->current_size], pf->format, offset);
	pf->current_size += offset;
	pf->format += offset;
}

void	pfstr(char const *s, t_pfvars *pf)
{
	size_t	len;

	len = ft_strlen(s);
	ft_memcpy(&(pf->buff)[pf->current_size], s, len);
	pf->current_size += len;
}
