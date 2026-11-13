/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:23:23 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/13 22:09:54 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_valid_int(char *str, int *val);
int	has_duplicate(t_stack *stack, int val);
int	count_total_elements(int argc, char **argv);

static int	stack_init(t_stack *stack, int size)
{
	if (size < 0)
		return (0);
	stack->size = 0;
	stack->capacity = (size_t)size;
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
		return (0);
	return (1);
}

static int	parse_flag(char *arg, t_ctx *ctx)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		ctx->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		ctx->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		ctx->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		ctx->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		ctx->bench = 1;
	else
		return (0);
	return (1);
}

static void	free_split(char **split_args)
{
	int	j;

	j = 0;
	if (!split_args)
		return ;
	while (split_args[j])
		free(split_args[j++]);
	free(split_args);
}

static int	process_arg(char *arg_str, t_ctx *ctx)
{
	char	**split_args;
	int		j;
	int		val;

	split_args = ft_split(arg_str, ' ');
	if (!split_args)
		return (0);
	j = 0;
	while (split_args[j])
	{
		if (!ft_is_valid_int(split_args[j], &val)
			|| has_duplicate(&ctx->a, val))
		{
			free_split(split_args);
			ft_print_error();
			return (0);
		}
		ctx->a.data[ctx->a.size].value = val;
		ctx->a.size++;
		j++;
	}
	free_split(split_args);
	return (1);
}

int	parse_args(int argc, char **argv, t_ctx *ctx)
{
	int	i;
	int	total_n;

	ctx->strategy = STRAT_ADAPTIVE;
	ctx->bench = 0;
	total_n = count_total_elements(argc, argv);
	if (total_n <= 0)
		return (0);
	if (!stack_init(&ctx->a, total_n) || !stack_init(&ctx->b, total_n))
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (!parse_flag(argv[i], ctx))
				return (ft_print_error(), free(ctx->a.data),
					free(ctx->b.data), 0);
		}
		else if (!process_arg(argv[i], ctx))
			return (free(ctx->a.data), free(ctx->b.data), 0);
	}
	return (1);
}
