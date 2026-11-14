/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:06:17 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 14:49:49 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	rotate(t_stack *s)
{
	t_elem	temp;
	size_t	i;

	if (s->size < 2)
		return (0);
	temp = s->data[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = temp;
	return (1);
}

void	ra(t_ctx *ctx)
{
	if (rotate(&ctx->a))
		write(1, "ra\n", 3);
}

void	rb(t_ctx *ctx)
{
	if (rotate(&ctx->b))
		write(1, "rb\n", 3);
}

void	rr(t_ctx *ctx)
{
	int	did_a;
	int	did_b;

	did_a = rotate(&ctx->a);
	did_b = rotate(&ctx->b);
	if (did_a || did_b)
		write(1, "rr\n", 3);
}
