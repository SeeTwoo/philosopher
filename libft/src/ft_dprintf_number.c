#include "libft.h"

size_t	nb_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

void	pfnbr(int n, t_pfvars *pf)
{
	size_t	len;
	char	*temp;

	if (n == INT_MIN)
	{
		ft_memcpy(&(pf->buff)[pf->current_size], INT_MIN_LIT, INT_MIN_LIT_LEN);
		pf->current_size += INT_MIN_LIT_LEN;
	}
	len = nb_len(n);
	if (n < 0)
	{
		pf->buff[pf->current_size] = '-';
		n *= -1;
	}
	temp = &(pf->buff)[pf->current_size + len - 1];
	while (n > 9)
	{
		*temp = (n % 10) + '0';
		n /= 10;
		temp--;
	}
	*temp = n + '0';
	pf->current_size += len;
}
