/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:34:18 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/05 10:54:53 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	res;

	while (ft_isspace(*nptr))
		nptr++;
	signe = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	res = 0;
	while (*nptr && (*nptr >= 48 && *nptr <= 57))
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * signe);
}
