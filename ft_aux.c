/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:03:34 by mpons             #+#    #+#             */
/*   Updated: 2021/11/19 18:16:45 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr_u(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	return (count);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	count;
	int	i;
	int	size_b;
	int	nbr_final[16];

	count = 0;
	i = 0;
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
	{
		count += ft_putchar(base[nbr_final[i]]);
	}
	return (count);
}
