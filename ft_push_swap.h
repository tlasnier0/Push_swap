/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:52 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 13:32:37 by tlasnier         ###   ########.fr       */
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



#endif
