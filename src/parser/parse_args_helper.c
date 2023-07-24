/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:21:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 20:30:54 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_arg_count(char **num_list)
{
	long long	cnt;

	cnt = 0;
	while (*num_list++)
		cnt++;
	return (cnt);
}

static void	compression_helper(t_stacks *stacks)
{
	long long	fixed;
	long long	idx;
	long long	cnt;

	fixed = 0;
	while (fixed < stacks->a.capacity)
	{
		idx = 0;
		cnt = 0;
		while (idx < stacks->a.capacity)
		{
			if (stacks->alpha[idx] < stacks->alpha[fixed])
				cnt++;
			idx++;
		}
		deque_push_back(&stacks->a, cnt);
		fixed++;
	}
}

void	compression(t_stacks *stacks, char **num_list)
{
	size_t	idx;

	idx = 0;
	while (num_list[idx])
	{
		stacks->alpha[idx] = ft_atoi(num_list[idx]);
		idx++;
	}
	compression_helper(stacks);
}
