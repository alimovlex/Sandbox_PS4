/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalimov <alalimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:18:01 by alalimov          #+#    #+#             */
/*   Updated: 2025/10/23 06:42:40 by alalimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ft_memcmp
 *
 * The ft_strlen() function computes the length of the string s.
 *
 * @param [s]: string to calculate the length.
 *
 * @returns The ft_strlen() function returns the number of characters 
 * that precede the terminating NUL character.
 * The ft_strlen() function returns the number of bytes in the string 
 * pointed to by s.
 * @retval  the number of characters that precede the terminating NUL character.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_one;
	unsigned char	*str_two;
	size_t			i;

	i = 0;
	str_one = (unsigned char *)s1;
	str_two = (unsigned char *)s2;
	while (i < n)
	{
		if (str_one[i] > str_two[i])
			return (1);
		else if (str_one[i] < str_two[i])
			return (-1);
		i++;
	}
	return (0);
}
