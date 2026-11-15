/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:41:57 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/15 15:36:35 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	put_op_fd(const char *name, size_t n, int fd)
{
	ft_putstr_fd((char *)name, fd);
	ft_putstr_fd(": ", fd);
	ft_putnbr_fd((int)n, fd);
}

void	put_ops_line1_fd(const t_ctx *ctx, int fd)
{
	ft_putstr_fd("[bench] ", fd);
	put_op_fd("sa", ctx->ops[SA], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("sb", ctx->ops[SB], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("ss", ctx->ops[SS], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("pa", ctx->ops[PA], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("pb", ctx->ops[PB], fd);
	ft_putchar_fd('\n', fd);
}

void	put_ops_line2_fd(const t_ctx *ctx, int fd)
{
	ft_putstr_fd("[bench] ", fd);
	put_op_fd("ra", ctx->ops[RA], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("rb", ctx->ops[RB], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("rr", ctx->ops[RR], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("rra", ctx->ops[RRA], fd);
	ft_putchar_fd(' ', fd);
	put_op_fd("rrb", ctx->ops[RRB], fd);
	ft_putchar_fd('\n', fd);
	put_op_fd("rrr", ctx->ops[RRR], fd);
	ft_putchar_fd('\n', fd);
}
