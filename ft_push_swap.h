/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:52 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 14:28:39 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stddef.h>

typedef struct s_stack
{
	int value;
}	t_stack;

typedef struct s_context
{
	t_stack *a_stack;
	t_stack *b_stack;
	int strategies;
	int bench;
}	t_context;

/// libft
int	ft_strcmp(const char *str1, const char *str2);

// ft_flag_parsing.c
t_context ft_flag_parsing (t_context context, int argc, char **argv);

#endif
