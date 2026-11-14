/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tom.lasnier@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:13:25 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/14 17:32:51 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int		ft_strncmp(const char s1[], const char s2[], size_t n);
char	**ft_split(const char *s, char c);
int		ft_isdigit(int c);
void	ft_bzero(void *ptr, size_t length);

#endif
