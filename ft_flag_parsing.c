/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:23:23 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 14:27:35 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_context assignflag(t_context context, int flag)
{
	if(flag == 0)
		return(context);
	else if(flag >= 1 && flag <= 3 && context.strategies != 0)
	{
		context.strategies = 9;
		return (context);
	}
	else if(flag == 4 && context.bench == 1)
	{
		context.bench = 9;
		return (context);
	}
	if(flag >= 1 && flag <= 3)
		context.strategies = flag;
	if(flag == 4)
		context.bench = 1;
	return(context);
	}

static int detectflag(char *str)
{
	if(!(str[0] == '-' && str[1] == '-'))
		return(0);
	else if(!ft_strcmp(str, "--simple"))
		return(1);
	else if(!ft_strcmp(str, "--medium"))
		return(2);
	else if(!ft_strcmp(str, "--complex"))
		return(3);
	else if(!ft_strcmp(str, "--adaptive"))
		return(4);
	else if(!ft_strcmp(str, "--bench"))
		return(9);
	else
		return(0);
}

t_context ft_flag_parsing (t_context context, int argc, char **argv)
{
	if(detectflag(argv[1]))
	{
		context = assignflag(context, detectflag(argv[1]));
		if(detectflag(argv[2]))
			context = assignflag(context, detectflag(argv[2]));
	}
	else if(detectflag(argv[argc - 1]))
	{
		context = assignflag(context, detectflag(argv[argc - 1]));
		if(detectflag(argv[argc-2]))
			context = assignflag(context, detectflag(argv[argc - 2]));
	}
	return (context);
}
