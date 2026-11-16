/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:15:36 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/15 15:31:15 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc <= 1)
		return (0);
	if (parse_args(argc, argv, &ctx) == 0)
		return (0);
	ctx.disorder = compute_disorder(&ctx.a);
	ft_push_swap(&ctx);
	if (ctx.bench)
		print_bench(&ctx);
	free(ctx.a.data);
	free(ctx.b.data);
	return (0);
}
