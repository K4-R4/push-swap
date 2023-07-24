/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:33:40 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 22:46:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(char **num_list)
{
	long long	cur;

	cur = LLONG_MIN;
	while (*num_list)
	{
		if (cur >= ft_atoi(*num_list))
			return (false);
		num_list++;
	}
	return (true);
}

bool	has_dup(char **num_list)
{
	long long	i;
	long long	j;

	i = 0;
	while (num_list[i])
	{
		j = 0;
		while (num_list[j])
		{
			if (i == j)
				continue ;
			if (ft_atoi(num_list[i]) == ft_atoi(num_list[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
