/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:17:07 by chbenhiz          #+#    #+#             */
/*   Updated: 2025/12/05 22:17:24 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr(n / 16);
	write(1, &base[n % 16], 1);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	ft_put_ptr(ptr);
	return (len + ft_len_ptr(ptr));
}
