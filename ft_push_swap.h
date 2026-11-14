/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:52 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/14 15:55:52 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include "./libft/libft.h"

# define THRESHOLD_LOW 2000
# define THRESHOLD_HIGH 5000

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
	size_t			disorder;
}	t_ctx;

int		parse_args(int argc, char **argv, t_ctx *ctx);
void	ft_print_error(void);
int		free_and_error(t_ctx *ctx, int print_err);
int		ft_is_valid_int(char *str, int *val);
int		has_duplicate(t_stack *stack, int val);
int		count_total_elements(int argc, char **argv);
void	sa(t_ctx *ctx);
void	sb(t_ctx *ctx);
void	ss(t_ctx *ctx);
void	pa(t_ctx *ctx);
void	pb(t_ctx *ctx);
void	ra(t_ctx *ctx);
void	rb(t_ctx *ctx);
void	rr(t_ctx *ctx);
void	rra(t_ctx *ctx);
void	rrb(t_ctx *ctx);
void	rrr(t_ctx *ctx);
size_t	compute_disorder(const t_stack *s);

#endif
