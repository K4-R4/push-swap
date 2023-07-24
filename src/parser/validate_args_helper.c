/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:33:40 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 23:33:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(char **num_list)
{
	int	prev;
	int	cur;

	prev = ft_atoi(*num_list);
	num_list++;
	while (*num_list)
	{
		cur = ft_atoi(*num_list);
		if (prev >= cur)
			return (false);
		prev = cur;
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
			{
				j++;
				continue ;
			}
			if (ft_atoi(num_list[i]) == ft_atoi(num_list[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
