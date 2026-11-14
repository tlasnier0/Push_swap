/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:06:17 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 14:49:41 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	push(t_stack *from, t_stack *to)
{
	size_t	i;

	if (from->size == 0)
		return (0);
	i = to->size;
	while (i > 0)
	{
		to->data[i] = to->data[i - 1];
		i--;
	}
	to->data[0] = from->data[0];
	to->size++;
	i = 0;
	while (i < from->size - 1)
	{
		from->data[i] = from->data[i + 1];
		i++;
	}
	from->size--;
	return (1);
}

void	pa(t_ctx *ctx)
{
	if (push(&ctx->b, &ctx->a))
		write(1, "pa\n", 3);
}

void	pb(t_ctx *ctx)
{
	if (push(&ctx->a, &ctx->b))
		write(1, "pb\n", 3);
}
