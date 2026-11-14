/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:43:42 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/14 15:54:26 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	compute_disorder(const t_stack *s)
{
	size_t	i;
	size_t	j;
	size_t	mistakes;
	size_t	total_pairs;

	if (!s || s->size < 2)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			total_pairs++;
			if (s->data[i].value > s->data[j].value)
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0);
	return ((mistakes * 10000) / total_pairs);
}
