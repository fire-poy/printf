/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:37:02 by mpons             #+#    #+#             */
/*   Updated: 2021/11/19 18:09:05 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_impression(const char *s, va_list args)
{
	int				i;
	int				count;
	unsigned long	v;

	count = 0;
	i = 0;
	v = 0;
	if (*s == '%')
		count = ft_putchar(s[i]);
	if (*s == 'c')
		count = ft_putchar(va_arg(args, int));
	if (*s == 's')
		count = ft_putstr(va_arg(args, char *));
	if (*s == 'p')
		count += ft_put_address(va_arg(args, unsigned long),
				"0123456789abcdef");
	if (*s == 'd' || *s == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (*s == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	if (*s == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (*s == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int				i;
	int				count;
	va_list			ap;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			count += ft_putchar(s[i]);
			i++;
		}
		if (s[i] == '%')
		{
			count += ft_impression(s + i + 1, ap);
			i += 2;
		}
	}
	va_end(ap);
	return (count);
}
/*
	printf("return = count = %d \n", count);

int	ft_fun(void *ptr, unsigned long *a)
{
	int	count;

	count = 0;
	*a = (unsigned long)ptr;
	count += ft_putchar('0');
	count += ft_putchar('x');
	return (count);
}

	{
		printf("v = %lu", v);
		count += ft_fun(va_arg(args, void*), &v);
		printf("v = %lu", v);
		count += ft_putnumber_hexa(v);
	}

uint64_t
write(1, "0x", 2);
printf("return = count = %d \n", count);
pour 'p'		    ft_putstr(ft_itoa_base(&ap));
*/
