/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:31:55 by moashraf          #+#    #+#             */
/*   Updated: 2025/07/19 12:46:28 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	check_overflow_ll(long long base, char c, int sign)
{
	long long	max_div_10;
	long long	max_mod_10;

	max_div_10 = LLONG_MAX / 10;
	max_mod_10 = LLONG_MAX % 10;
	if (sign > 0)
	{
		if (base > max_div_10)
			return (1);
		if (base == max_div_10 && (c - '0') > max_mod_10)
			return (1);
	}
	if (sign < 0)
	{
		if (base > max_div_10)
			return (-1);
		if (base == max_div_10 && (c - '0') > max_mod_10)
			return (-1);
	}
	return (0);
}

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static long long	convert_number(const char *str, int sign, int *i)
{
	long long	base;
	int			overflow;

	base = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		overflow = check_overflow_ll(base, str[*i], sign);
		if (overflow == 1)
			return (LLONG_MAX);
		else if (overflow == -1)
			return (LLONG_MIN);
		base = base * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (base * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result_ll;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	sign = handle_sign(str, &i);
	result_ll = convert_number(str, sign, &i);
	return ((int)result_ll);
}
