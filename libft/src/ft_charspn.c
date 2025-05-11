/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:31:24 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/10 09:32:36 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charspn(char const *s, char reject)
{
	char	*end;

	end = ft_strchr(s, reject);
	if (!end)
		return (ft_strlen(s));
	return (end - s);
}
