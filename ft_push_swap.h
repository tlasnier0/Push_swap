/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:52 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 13:33:51 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include "./libft/libft.h"

typedef struct s_elem
{
	int	value;
}	t_elem;

typedef struct s_stack
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
}	t_strategy;

typedef enum e_complexity
{
	CPLX_N23,
	CPLX_NSQRTN,
	CPLX_NLOGN
}	t_complexity;

typedef struct s_ctx
{
	t_stack			a;
	t_stack			b;
	t_strategy		strategy;
	t_complexity	complexity;
	int				bench;
}	t_ctx;

int		parse_args(int argc, char **argv, t_ctx *ctx);
void	ft_print_error(void);
int		free_and_error(t_ctx *ctx, int print_err);
int		ft_is_valid_int(char *str, int *val);
int		has_duplicate(t_stack *stack, int val);
int		count_total_elements(int argc, char **argv);

#endif
