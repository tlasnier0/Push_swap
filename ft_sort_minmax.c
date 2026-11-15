/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_minmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:26:32 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/15 15:26:33 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static size_t	rotation_cost(size_t size, size_t pos)
{
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

static void	push_to_b(t_ctx *ctx, size_t pos, int is_max)
{
	rotate_a_to(ctx, pos);
	pb(ctx);
	if (is_max)
		rb(ctx);
}

void	sort_minmax(t_ctx *ctx)
{
	size_t	pos_min;
	size_t	pos_max;

	if (is_sorted(&ctx->a))
		return ;
	while (ctx->a.size > 0)
	{
		pos_min = find_min_pos(&ctx->a);
		pos_max = find_max_pos(&ctx->a);
		if (rotation_cost(ctx->a.size, pos_min)
			<= rotation_cost(ctx->a.size, pos_max))
			push_to_b(ctx, pos_min, 0);
		else
			push_to_b(ctx, pos_max, 1);
	}
	rotate_b_to(ctx, find_max_pos(&ctx->b));
	while (ctx->b.size > 0)
		pa(ctx);
}
