/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:28:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 14:01:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_digits(long long nbr)
{
	int	l;
	l = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 10;
		l++;
	}
	return (l);
}

// args must be separated by space(s)
bool	is_valid_arg(char **num_list)
{
	bool	is_valid;
	bool	is_negative;

	is_valid = true;
	while (*num_list)
	{
		is_negative = *num_list[0] == '-';
		if (ft_strlen(*num_list) - is_negative !=
				count_digits(ft_atoi(*num_list)))
			return (false);
		num_list++;
	}
	return (is_valid);
}
