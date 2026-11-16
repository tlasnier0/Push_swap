/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:16:30 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/16 12:17:10 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static size_t	count_bits(size_t max)
{
	size_t	bits;

	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

static void	radix_pass(t_ctx *ctx, size_t bit)
{
	size_t	i;
	size_t	size;

	size = ctx->a.size;
	i = 0;
	while (i < size)
	{
		if ((ctx->a.data[0].index >> bit) & 1)
			ra(ctx);
		else
			pb(ctx);
		i++;
	}
	while (ctx->b.size > 0)
		pa(ctx);
}

void	sort_radix(t_ctx *ctx)
{
	size_t	bit;
	size_t	max_bits;

	if (is_sorted(&ctx->a))
		return ;
	index_stack(&ctx->a);
	max_bits = count_bits(ctx->a.size - 1);
	bit = 0;
	while (bit < max_bits && !is_sorted(&ctx->a))
		radix_pass(ctx, bit++);
}
