/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:00:16 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/24 10:45:38 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress_recursive(unsigned long nbrr, char *base)
{
	int	len;

	len = 0;
	if (nbrr == 0)
		return (0);
	len += ft_putaddress_recursive(nbrr / 16, base);
	ft_putchar(base[nbrr % 16]);
	len++;
	return (len);
}

int	ft_putaddress(unsigned long nbr)
{
	int					len;
	char				*base;
	unsigned long long	nbrr;

	len = 2;
	nbrr = nbr;
	base = "0123456789abcdef";
	if (nbrr == 0)
	{
		ft_putchar('0');
		return (len + 1);
	}
	len += ft_putaddress_recursive(nbrr, base);
	return (len);
}
