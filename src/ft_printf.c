/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:21:17 by jdomingu          #+#    #+#             */
/*   Updated: 2022/06/21 14:02:57 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		len = ft_strlen(s);
	}
	return (len);
}

int	ft_print_param(va_list args, char c)
{
	int	len;

	len = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == 'd' || c == 'i')
		len = ft_print_nbr(va_arg(args, int));
	else if (c == 'p')
		len = ft_print_pointer((unsigned long long)va_arg(args, void *));
	else if (c == 'u')
		len = ft_print_unbr(va_arg(args, unsigned int));
	else
		ft_putchar_fd(c, 1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		else
		{
			len += ft_print_param(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
