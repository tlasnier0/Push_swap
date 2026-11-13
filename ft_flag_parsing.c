/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:23:23 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/13 14:38:54 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

static int	count_total_elements(int argc, char **argv)
{
	int		count;
	int		i;
	char	**split_args;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			i++;
			continue ;
		}
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			return (-1);
		j = 0;
		while (split_args[j])
		{
			count++;
			j++;
		}
		j = 0;
		while (split_args[j])
			free(split_args[j++]);
		free(split_args);
		i++;
	}
	return (count);
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
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (ft_strncmp(argv[i], "--simple", 8) == 0)
				ctx->strategy = STRAT_SIMPLE;
			else if (ft_strncmp(argv[i], "--medium", 8) == 0)
				ctx->strategy = STRAT_MEDIUM;
			else if (ft_strncmp(argv[i], "--complex", 9) == 0)
				ctx->strategy = STRAT_COMPLEX;
			else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
				ctx->strategy = STRAT_ADAPTIVE;
			else if (ft_strncmp(argv[i], "--bench", 7) == 0)
				ctx->bench = 1;
			else
				return (0);
		}
		else {

		}
		i++;
	}
	return (1);
}
