/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:05:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/16 17:14:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Move elements of the specified closed section from stack A to stack B
static void		quick_sort(t_stacks *stacks, char cur_sta, long long start, long long end)
{
	long long	cnt;
	long long	*num;

	cnt = 0;
	while (cnt < end - start + 1)
	{
		num = deque_get_front(&stacks->a);
		if (!num)
			return ;
		if (start <= *num && *num <= end)
		{
			stack_pb(stacks);
			cnt++;
		}
		else
			stack_ra(stacks);
	}
}

void	sort(t_stacks *stacks)
{
}
