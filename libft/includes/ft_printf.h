/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:10:53 by walter            #+#    #+#             */
/*   Updated: 2025/04/04 03:18:14 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxXf"
# endif

typedef struct s_pfvars	t_pfvars;

struct s_pfvars
{
	char		buff[1024];
	char const	*format;
	size_t		piece_size;
	int			current_size;
	int			ret_val;
	va_list		arg;
	va_list		arg_cpy;
	int			fd;
};

int			ft_printf(char const *format, ...);
int			ft_putchar(char c);
int			ft_puthex(unsigned int n, char *base);
int			ft_putlhex(unsigned long n, char *base);
int			ft_putnbr(long long n);
int			ft_putptr(void *ptr);
int			ft_putstr(char *s);
int			ft_putunbr(unsigned int n);

#ifndef INT_MIN_LIT
# define INT_MIN_LIT "-2147483648"
#endif

#ifndef INT_MIN_LIT_LEN
# define INT_MIN_LIT_LEN 11
#endif

int			buffer_is_full(t_pfvars *pf);
void		flush_buffer(t_pfvars *pf);
void		fill_buffer(t_pfvars *pf);
int			ft_dprintf(int fd, char const *format, ...);
size_t		nb_len(int n);
void		parse_specifier(t_pfvars *pf);
void		pfnbr(int n, t_pfvars *pf);
void		pfstr(char const *s, t_pfvars *pf);
void		regular_format(t_pfvars *pf);

#endif
