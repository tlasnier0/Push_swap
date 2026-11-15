/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:06:17 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/15 15:37:39 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	swap(t_stack *s)
{
	t_elem	temp;

	if (s->size < 2)
		return (0);
	temp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = temp;
	return (1);
}

void	sa(t_ctx *ctx)
{
	if (swap(&ctx->a))
	{
		write(1, "sa\n", 3);
		ctx->ops[SA]++;
	}
}

void	sb(t_ctx *ctx)
{
	if (swap(&ctx->b))
	{
		write(1, "sb\n", 3);
		ctx->ops[SB]++;
	}
}

void	ss(t_ctx *ctx)
{
	int	a;
	int	b;

	a = swap(&ctx->a);
	b = swap(&ctx->b);
	if (a || b)
	{
		write (1, "ss\n", 3);
		ctx->ops[SS]++;
	}
}
