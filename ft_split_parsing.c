/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:11:40 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/13 17:21:57 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int ft_is_number(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] <= '0' && str[i] >= '9')
			return(0);
		i++;
	}
	return(1);
}

t_parsing ft_split_parse(int argc, char **argv)
{
	t_parsing prs;
	int i;
	int j;

	i = 1;
	j = 0;
	while(i <= 2 && argv[i][0] == '-' && argv[i][1] == '-' && i < argc)
	{
		if(i == 1)
			prs.flag1 = argv[i];
		else
			prs.flag2 = argv[i];
		i++;
	}
	while(ft_is_number(argv[i]))
	{
		//mettre ft_atoi(argv[i]) dans prs.stack[j] avec une fonc qui malloc a lavance en regardant combien de arg quil reste
	}
	if(argv[i])
		//return(ERROR);
	return(prs);
}
