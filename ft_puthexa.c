/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:00:19 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/24 10:47:00 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nbr, char C)
{
	char				*base;
	int					len;
	unsigned long long	nbrr;

	len = 0;
	nbrr = nbr;
	if (C == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbrr < 16)
	{
		ft_putchar(base[nbrr % 16]);
		len++;
	}
	else
	{
		len += ft_putnbr_base(nbrr / 16, base);
		len += ft_putnbr_base(nbrr % 16, base);
	}
	return (len);
}
