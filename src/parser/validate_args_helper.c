/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:33:40 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 19:30:43 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

bool	is_sorted(t_stacks *stacks)
{
	long long	idx;
	long long	prev;
	long long	cur;

	idx = 0;
	prev = deque_get_at(&stacks->a, idx++);
	cur = deque_get_at(&stacks->a, idx);
	while (idx < stacks->a.sz)
	{
		if (prev >= cur)
			return (false);
		prev = deque_get_at(&stacks->a, idx++);
		cur = deque_get_at(&stacks->a, idx);
	}
	return (true);
}
