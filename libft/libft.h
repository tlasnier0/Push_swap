/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:13:25 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/13 10:44:09 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int		ft_strncmp(const char s1[], const char s2[], size_t n);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *nptr);

#endif
