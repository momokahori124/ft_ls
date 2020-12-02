/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momoka <momoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:09:50 by mhori             #+#    #+#             */
/*   Updated: 2020/12/01 00:05:18 by momoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*save;

	if (!lst)
		return (0);
	save = lst;
	count = 1;
	while (save->next)
	{
		count++;
		save = save->next;
	}
	return (count);
}
