/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:20:23 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/16 12:20:23 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	index_stack(t_stack *s)
{
	size_t	i;
	size_t	j;
	size_t	rank;

	i = 0;
	while (i < s->size)
	{
		rank = 0;
		j = 0;
		while (j < s->size)
		{
			if (s->data[j].value < s->data[i].value)
				rank++;
			j++;
		}
		s->data[i].index = rank;
		i++;
	}
}
