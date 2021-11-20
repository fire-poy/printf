/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:42:54 by mpons             #+#    #+#             */
/*   Updated: 2021/11/19 18:17:15 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_put_address(unsigned long nbr, char *base)
{
	int	i;
	int	count;
	int	size_b;
	int	nbr_final[16];

	count = 0;
	i = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	size_b = 16;
	if (nbr == 0)
	{
		count += ft_putchar(nbr + 48);
		return (count);
	}
	while (nbr)
	{
		nbr_final[i] = nbr % size_b;
		nbr = nbr / size_b;
		i++;
	}
	while (--i >= 0)
		count += ft_putchar(base[nbr_final[i]]);
	return (count);
}
/*
int	ft_putnumber_hexa(unsigned long n)
{
    int	count;

    count = 0;
	if (n > 15)
        count += ft_putnumber_hexa(n / 16);
        n = n % 16;
    if (n > 9 && n <16)
        count += ft_putchar(87 + n);
    if (n >= 0 && n < 10)
        count += ft_putchar(48 + n);
    return (count);
}
*/
