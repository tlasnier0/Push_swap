/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:15:36 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 14:35:34 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	struct s_context context;

	if(argc <= 1) //valeure a changer
		return(0);
	context = ft_flag_parsing(context, argc, argv);
	if(context.strategies == 9 || context.bench == 9)
		return(0);
}
