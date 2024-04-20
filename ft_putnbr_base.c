/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:00:27 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/24 10:48:43 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int					len;
	size_t				len_base;
	unsigned long long	nbrr;

	len = 0;
	nbrr = nbr;
	len_base = ft_strlen(base);
	if (nbrr < len_base)
	{
		ft_putchar(base[nbrr % len_base]);
		len++;
	}
	else
	{
		len += ft_putnbr_base(nbrr / len_base, base);
		len += ft_putnbr_base(nbrr % len_base, base);
	}
	return (len);
}
