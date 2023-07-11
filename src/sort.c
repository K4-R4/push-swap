/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:05:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/12 00:17:27 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Move elements of the specified closed section from stack A to stack B
static void		transfer_stack_range(t_stacks *stacks, long long start, long long end)
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

static void		transfer_back_stack(t_stacks *stacks)
{
}

void	sort(t_stacks *stacks)
{
	long long	pivot1;
	long long	pivot2;

	(void)pivot2;
	pivot1 = stacks->a.capacity / 3;
	pivot2 = stacks->a.capacity - pivot1;
	transfer_stack_range(stacks, pivot2, stacks->a.capacity - 1);
	transfer_stack_range(stacks, pivot1, pivot2 - 1);
	transfer_stack_range(stacks, 0, pivot1 - 1);
}
