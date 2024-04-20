/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:00:22 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/23 12:45:18 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_putnbr(int c)
{
	write(1, &c, 1);
}

int	ft_count_digits(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long int	ln;
	int			len;

	len = 0;
	ln = n;
	if (ln < 0)
	{
		ft_putchar_putnbr('-');
		ln *= -1;
	}
	if (ln < 10)
	{
		ft_putchar_putnbr(ln + 48);
	}
	else
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
	if (n <= 0)
		len++;
	len += ft_count_digits(ln);
	return (len);
}
