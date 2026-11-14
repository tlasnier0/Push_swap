/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:02:54 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/14 17:45:37 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	put_percent_fd(size_t permyriad, int fd)
{
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(permyriad / 100, fd);
	ft_putchar_fd('.', fd);
	if (permyriad % 100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(permyriad % 100, fd);
	ft_putstr_fd("%\n", fd);
}

static void	put_strategy_fd(const t_ctx *ctx, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (ctx->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple", fd);
	else if (ctx->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium", fd);
	else if (ctx->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex", fd);
	else if (ctx->strategy == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptive", fd);
	ft_putstr_fd(" / ", fd);
	if (ctx->complexity == CPLX_N23)
		ft_putstr_fd("O(n^2)", fd);
	else if (ctx->complexity == CPLX_NSQRTN)
		ft_putstr_fd("O(n√n)", fd);
	else if (ctx->complexity == CPLX_NLOGN)
		ft_putstr_fd("O(n log n)", fd);
	ft_putchar_fd('\n', fd);
}

static size_t	total_ops(const t_ctx *ctx)
{
	size_t	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += ctx->ops[i++];
	return (total);
}

void	print_bench(const t_ctx *ctx)
{
	put_percent_fd(ctx->disorder, 2);
	put_strategy_fd(ctx, 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd((int)total_ops(ctx), 2);
	ft_putchar_fd('\n', 2);
	put_ops_line1_fd(ctx, 2);
	put_ops_line2_fd(ctx, 2);
}
