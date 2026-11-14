/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:15:36 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 13:50:13 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
#include <stdio.h>
static void	print_debug(t_ctx *ctx)
{
	size_t	i;

	printf("---DEBUG PARSING---\n");
	printf("Strategy: ");
	if (ctx->strategy == STRAT_SIMPLE) printf("SIMPLE\n");
	else if (ctx->strategy == STRAT_MEDIUM) printf("MEDIUM\n");
	else if (ctx->strategy == STRAT_COMPLEX) printf("COMPLEX\n");
	else if (ctx->strategy == STRAT_ADAPTIVE) printf("ADAPTIVE\n");

	printf("Bench mode: %s\n", ctx->bench ? "ON" : "OFF");

	printf("Strack A (size: %zu, capacity: %zu):\n[",
		 ctx->a.size, ctx->a.capacity);
	i = 0;
	while (i < ctx->a.size)
		printf("%d", ctx->a.data[i++].value);
	printf("]\n---DEBUG PARSING---");
}
*/

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc <= 1)
		return (0);
	if (parse_args(argc, argv, &ctx) == 0)
		return (0);
	// print_debug(&ctx);
	// Lancer l algo
	free(ctx.a.data);
	free(ctx.b.data);
	return (0);
}
