/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parsing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:00:06 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/14 13:49:31 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_check_sign(char *str, int *i, long *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (str[*i] != '\0');
}

int	ft_is_valid_int(char *str, int *val)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str || !val || !ft_check_sign(str, &i, &sign))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i] - '0');
		if ((sign * res) > INT_MAX || (sign * res) < INT_MIN)
			return (0);
		i++;
	}
	*val = (int)(sign * res);
	return (1);
}

int	has_duplicate(t_stack *stack, int val)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i].value == val)
			return (1);
		i++;
	}
	return (0);
}

int	count_total_elements(int argc, char **argv)
{
	int		count;
	int		i;
	int		j;
	char	**split_args;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--", 2))
			continue ;
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			return (-1);
		j = 0;
		while (split_args[j])
			free(split_args[j++]);
		count += j;
		free(split_args);
	}
	return (count);
}
