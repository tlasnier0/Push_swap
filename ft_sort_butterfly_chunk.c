/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_butterfly_chunk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:17:12 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/15 15:29:12 by tlasnier         ###   ########.fr       */
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

static size_t	ft_sqrt(size_t n)
{
	size_t	r;

	r = 1;
	while (r * r < n)
		r++;
	return (r);
}

static void	push_chunks_to_b(t_ctx *ctx, size_t chunk)
{
	size_t	i;

	i = 0;
	while (ctx->a.size > 0)
	{
		if (ctx->a.data[0].index <= i)
		{
			pb(ctx);
			rb(ctx);
			i++;
		}
		else if (ctx->a.data[0].index <= i + chunk)
		{
			pb(ctx);
			i++;
		}
		else
			ra(ctx);
	}
}

void	sort_butterfly_chunk(t_ctx *ctx)
{
	if (is_sorted(&ctx->a))
		return ;
	index_stack(&ctx->a);
	push_chunks_to_b(ctx, ft_sqrt(ctx->a.size));
	while (ctx->b.size > 0)
	{
		rotate_b_to(ctx, find_max_pos(&ctx->b));
		pa(ctx);
	}
}
