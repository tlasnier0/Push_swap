/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:40:19 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/14 13:49:42 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}

int	free_and_error(t_ctx *ctx, int print_err)
{
	if (print_err)
		ft_print_error();
	free(ctx->a.data);
	free(ctx->b.data);
	return (0);
}
