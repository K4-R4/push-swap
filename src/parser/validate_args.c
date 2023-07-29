/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:28:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 11:14:23 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	will_overflow_helper(long *nb, int digit, int sign)
{
	if (*nb * sign > INT_MAX / 10 || (*nb * sign == INT_MAX / 10
			&& digit > INT_MAX % 10))
		return (true);
	if (*nb * sign < INT_MIN / 10 || (*nb * sign == INT_MIN / 10 && digit
			> -(INT_MIN % 10)))
		return (true);
	return (false);
}

static bool	will_overflow(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (will_overflow_helper(&nb, *str - '0', sign))
			return (true);
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (false);
}

static bool	is_number(char *nbr)
{
	long long	idx;

	if (!ft_strlen(nbr))
		return (false);
	if (will_overflow(nbr))
		return (false);
	idx = 0;
	if (nbr[idx] && nbr[idx] == '-')
		idx++;
	if (nbr[idx] && nbr[idx] == '0' && ft_strlen(nbr) != 1)
		return (false);
	while (nbr[idx])
	{
		if (!ft_isdigit(nbr[idx]))
			return (false);
		idx++;
	}
	return (true);
}

static bool	is_numbers(char **num_list)
{
	if (!*num_list)
		return (false);
	while (*num_list)
	{
		if (!is_number(*num_list))
		{
			return (false);
		}
		num_list++;
	}
	return (true);
}

// args must be separated by space(s)
bool	is_valid_arg(char **num_list)
{
	if (!is_numbers(num_list))
		return (false);
	if (has_dup(num_list))
		return (false);
	return (true);
}
