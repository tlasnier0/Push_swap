/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:15:36 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 21:21:42 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc <= 1) // valeur a changer
		return(0);
	if (parse_args(argc, argv, &ctx) == 0)
		return (0);
}
