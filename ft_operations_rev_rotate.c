/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rev_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:06:17 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 14:46:59 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	rev_rotate(t_stack *s)
{
	t_elem	temp;
	size_t	i;

	if (s->size < 2)
		return (0);
	temp = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = temp;
	return (1);
}

void	rra(t_ctx *ctx)
{
	if (rev_rotate(&ctx->a))
		write(1, "rra\n", 4);
}

void	rrb(t_ctx *ctx)
{
	if (rev_rotate(&ctx->b))
		write(1, "rrb\n", 4);
}

void	rrr(t_ctx *ctx)
{
	int	did_a;
	int	did_b;

	did_a = rev_rotate(&ctx->a);
	did_b = rev_rotate(&ctx->b);
	if (did_a || did_b)
		write(1, "rrr\n", 4);
}
