/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:02:05 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/24 03:43:40 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_helper_printf(const char str, va_list list)
{
	void	*ptr;
	int		len;

	len = 0;
	if (str == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (str == 'x' || str == 'X')
		return (ft_puthexa(va_arg(list, unsigned int), str));
	else if (str == 'u')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789"));
	else if (str == 'p')
	{
		ptr = va_arg(list, void *);
		if (ptr == NULL)
			return (ft_putstr_p(ptr));
		write(1, "0x", 2);
		return (ft_putaddress((unsigned long)ptr));
	}
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_helper_printf(str[i + 1], list);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
/*int main()
{
	int *p;
	p = 4;
	ft_printf("%d\n",ft_printf("%x", 36027610530650132));
	printf("%d\n",printf ("%p", &p));
	ft_printf("hello world\n");
	printf("hello world");
}*/