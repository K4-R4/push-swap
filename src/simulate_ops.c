/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/19 13:48:54 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// Get how many operations are needed given a stack B front
static long long		simulate_a_ops(t_stacks *stacks, long long b_front)
{
	long long	idx_a;
	long long	a_front;
	long long	a_back;

	a_front = stack_get_at(stacks, 'a', 0);
	a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);

	if (b_front == a_front - 1)
		return (1);
	else if (b_front >= a_back)
		return (2);
	else if (b_front < a_back)
	{
		idx_a = stacks->a.sz - 1;
		while (b_front < a_back && a_back != stacks->a.capacity - 1)
		{
			stack_rrotate(stacks, 'a');
			a_back = stack_get_at(stacks, 'a', idx_a);
			idx_a--;
		}
		return ((stacks->a.capacity - idx_a) * 2 + 1);
	}
	return (-1);
}

static void	simulate_b_ops(t_stacks *stacks)
{
	long long	idx_b;
	long long	ele;
	long long	ops;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		if (idx_b < stacks->b.sz / 2)
			ops = idx_b;
		else
			ops = -(stacks->b.sz - idx_b);
		stacks->beta[idx_b] = ops;
		idx_b++;
	}
}

void	simulate_ops(t_stacks *stacks)
{
	long long idx_b;

	simulate_b_ops(stacks);
	while (idx_b < stacks->b.sz)
	{
		stacks->alpha[idx_b] = simulate_a_ops(stacks, stack_get_at(stacks, 'b', idx_b));
		idx_b++;
	}
}
