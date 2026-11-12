/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:32:38 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/12 13:30:33 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_strncmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/* #include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	(void)argc;
	printf("   strncmp: %d\nft_strncmp: %d\n",
	strncmp(argv[1], argv[2], ft_atoi(argv[3])),
	ft_strncmp(argv[1], argv[2], ft_atoi(argv[3])));
} */
