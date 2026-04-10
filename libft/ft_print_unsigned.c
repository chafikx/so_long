/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:16:59 by chbenhiz          #+#    #+#             */
/*   Updated: 2025/12/05 22:17:25 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (ft_len_unsigned(n));
}
