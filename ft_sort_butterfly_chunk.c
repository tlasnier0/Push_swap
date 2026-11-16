/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_butterfly_chunk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:20:45 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/16 12:21:22 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
