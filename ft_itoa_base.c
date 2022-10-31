/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:29:05 by fdaumas           #+#    #+#             */
/*   Updated: 2022/10/31 21:42:58 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*digit_equal_zero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

/**
 * Allocate with malloc and returns a string of the parametric digit converted
 * with the provided base, not manage a negative
 * @param char *str is NULL
 * @return allocate string of your digit converted
 */
char	*ft_itoa_base(int digit, int length, char *base, char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = digit;
	while (nb > 0)
	{
		nb = nb / length;
		i++;
	}
	if (!str)
	{
		if (digit == 0)
			return (digit_equal_zero());
		str = ft_calloc(sizeof(char), (i + 1));
		if (!str)
			return (NULL);
		str[i] = '\0';
	}
	if (digit >= length)
		ft_itoa_base(digit / length, length, base, str);
	str[i - 1] = base[digit % length];
	return (str);
}
