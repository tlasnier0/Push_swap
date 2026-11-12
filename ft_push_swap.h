/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:52 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 21:21:37 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stddef.h>
# include "./libft/libft.h"

typedef struct	s_elem
{
	int value;
}	t_elem;

typedef struct	s_stack
{
	t_elem	*data;
	size_t	size;
	size_t	capacity;
}	t_stack;

typedef enum e_strategy
{
    STRAT_SIMPLE,
    STRAT_MEDIUM,
    STRAT_COMPLEX,
    STRAT_ADAPTIVE
}    t_strategy;

typedef enum e_complexity
{
  CPLX_N23,
  CPLX_NSQRTN,
  CPLX_NLOGN
}    t_complexity;



typedef struct	s_ctx
{
	t_stack			a;
	t_stack 		b;
	t_strategy		strategy;
	t_complexity	complexity;
	int				bench;
}	t_ctx;

int	parse_args(int argc, char **argv, t_ctx *ctx);

#endif
