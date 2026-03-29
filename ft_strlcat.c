/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:08:04 by moashraf          #+#    #+#             */
/*   Updated: 2025/07/18 16:36:18 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = 0;
	while (src[slen])
		slen++;
	dlen = 0;
	while (dlen < destsize && dest[dlen])
		dlen++;
	if (dlen == destsize)
		return (destsize + slen);
	i = 0;
	while (src[i] && dlen + i + 1 < destsize)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	if (dlen + i < destsize)
		dest[dlen + i] = '\0';
	return (dlen + slen);
}
