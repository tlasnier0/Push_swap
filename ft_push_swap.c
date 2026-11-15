/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:26:54 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/15 15:41:31 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	run_adaptive(t_ctx *ctx)
{
	if (ctx->disorder < THRESHOLD_LOW)
	{
		ctx->complexity = CPLX_N23;
		sort_minmax(ctx);
	}
	else if (ctx->disorder < THRESHOLD_HIGH)
	{
		ctx->complexity = CPLX_NSQRTN;
		sort_butterfly_chunk(ctx);
	}
	else
	{
		ctx->complexity = CPLX_NLOGN;
		sort_radix(ctx);
	}
}

void	ft_push_swap(t_ctx *ctx)
{
	if (ctx->strategy == STRAT_SIMPLE)
	{
		ctx->complexity = CPLX_N23;
		sort_minmax(ctx);
	}
	else if (ctx->strategy == STRAT_MEDIUM)
	{
		ctx->complexity = CPLX_NSQRTN;
		sort_butterfly_chunk(ctx);
	}
	else if (ctx->strategy == STRAT_COMPLEX)
	{
		ctx->complexity = CPLX_NLOGN;
		sort_radix(ctx);
	}
	else if (ctx->strategy == STRAT_ADAPTIVE)
		run_adaptive(ctx);
}
