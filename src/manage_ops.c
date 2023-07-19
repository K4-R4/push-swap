/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:12:32 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/19 13:54:09 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_a_back_helper(t_stacks *stacks, long long b_front, long long a_back)
{
	long long	cnt;

	cnt = 0;
	if (b_front >= a_back)
	{
		stack_push(stacks, 'a');
		stack_rotate(stacks, 'a');
	}
	else if (b_front < a_back)
	{
		while (b_front < a_back && a_back != stacks->a.capacity - 1)
		{
			stack_rrotate(stacks, 'a');
			a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);
			cnt++;
		}
		stack_push(stacks, 'a');
		while (cnt + 1)
		{
			stack_rotate(stacks, 'a');
			cnt--;
		}
	}
}

#include "push_swap.h"
void		push_a_back(t_stacks *stacks)
{
	long long	b_front;
	long long	a_front;
	long long	a_back;

	while (stacks->b.sz)
	{
		b_front = stack_get_at(stacks, 'b', 0);
		a_front = stack_get_at(stacks, 'a', 0);
		a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);
		if (b_front == a_front - 1)
		{
			stack_push(stacks, 'a');
			a_front = stack_get_at(stacks, 'a', 0);
			a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);
			while (a_front - 1 == a_back)
			{
				stack_rrotate(stacks, 'a');
				a_front = stack_get_at(stacks, 'a', 0);
				a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);
			}
		}
		else
			push_a_back_helper(stacks, b_front, a_back);
	}
}
