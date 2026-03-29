/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:47:30 by moashraf          #+#    #+#             */
/*   Updated: 2025/07/19 11:50:43 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	cc;

	result = NULL;
	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			result = (char *)s;
		s++;
	}
	if (*s == cc)
		result = (char *)s;
	return (result);
}
