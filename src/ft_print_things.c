/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:25:06 by jdomingu          #+#    #+#             */
/*   Updated: 2022/06/21 18:06:59 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned long long value, char mode)
{
	int	len;

	len = 0;
	if (value >= 16)
	{
		len += ft_print_hex(value / 16, mode);
		len += ft_print_hex(value % 16, mode);
	}
	else
	{
		if (mode == 'X')
			ft_putchar_fd("0123456789ABCDEF"[value], 1);
		else
			ft_putchar_fd("0123456789abcdef"[value], 1);
		len++;
	}
	return (len);
}

int	ft_print_nbr(int value)
{
	char	*s;
	int		len;

	s = ft_itoa(value);
	ft_putnbr_fd(value, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_nbrlen(unsigned int value)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 10;
		len++;
	}
	return (len);
}

int	ft_print_unbr(unsigned int value)
{
	char	*s;
	int		len;

	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = ft_nbrlen(value);
	s = (char *) ft_calloc((len + 1), sizeof(char));
	while (value != 0)
	{
		s[len - 1] = (value % 10) + '0';
		value /= 10;
		len--;
	}
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_print_pointer(unsigned long long value)
{
	int	len;

	ft_putstr_fd("0x", 1);
	len = 2;
	if (value == 0)
		len += write(1, "0", 1);
	else
		len += ft_print_hex(value, 'x');
	return (len);
}
