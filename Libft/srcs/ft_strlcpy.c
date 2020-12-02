/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momoka <momoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:42:05 by mhori             #+#    #+#             */
/*   Updated: 2020/12/01 00:05:18 by momoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	int				count;
	char			*tmp;

	if (!dest || !src)
		return (-1);
	tmp = (char *)src;
	count = 0;
	i = 0;
	while (*(tmp++))
		count++;
	if (size <= 0)
		return (count);
	while (*src && i < size - 1)
	{
		*(dest++) = *(src++);
		i++;
	}
	*dest = '\0';
	return (count);
}
