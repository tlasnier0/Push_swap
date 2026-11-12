/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:15:36 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 14:12:28 by tlasnier         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	struct s_context context;

	if(argc <= 1)
		return(0);
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
	if(context.strategies == 9 || context.bench == 9)
		return(0);
	//ici on a donc un context mis a jour selon le premier flag et deuxieme flag ou dernier et avant dernier flag. si deux flags se contredisaient ca return(0). ATTENTION si il y a des flags a la fin et au debut, il va faloir return 0 au moment ou on tombe sur un flag a la fin alors que il y en a au debut
}
