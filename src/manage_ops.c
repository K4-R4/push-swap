/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:12:32 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/19 20:50:54 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// Rotate or reverse rotate stack B til its top has the the least-ops-ele
static void		rotate_b_til_target(t_stacks *stacks, long long min_idx_b)
{
	if (stacks->beta[min_idx_b] > 0)
	{
		while (stacks->beta[min_idx_b])
		{
			stack_rotate(stacks, 'b');
			stacks->beta[min_idx_b]--;
		}
	}
	else
	{
		while (stacks->beta[min_idx_b])
		{
			stack_rrotate(stacks, 'b');
			stacks->beta[min_idx_b]++;
		}
	}
}

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

static void		push_a_back(t_stacks *stacks)
{
	long long	b_front;
	long long	a_front;
	long long	a_back;

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

static long long	my_abs(long long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

/*
static long long	my_min(long long a, long long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
*/

void		execute_ops(t_stacks *stacks)
{
	long long	idx_b;
	long long	min_idx_b;
	long long	ops;
	long long	min_ops;

	while (stacks->b.sz)
	{
		idx_b = 0;
		min_ops = LLONG_MAX;
		simulate_ops(stacks);
		while (idx_b < stacks->b.sz)
		{
			ops = stacks->alpha[idx_b] + my_abs(stacks->beta[idx_b]);
			if (ops < min_ops)
			{
				min_idx_b = idx_b;
				min_ops = ops;
			}
			idx_b++;
		}
		/*
		if (stacks->beta[min_idx_b] < 0)
		{
			ops = my_min(stacks->alpha[min_idx_b], my_abs(stacks->beta[min_idx_b]));
			stacks->alpha[min_idx_b] -= ops;
			stacks->beta[min_idx_b] -= ops;
		}
		while (ops--)
			stack_rr(stacks);
		*/
		rotate_b_til_target(stacks, min_idx_b);
		push_a_back(stacks);
	}
}
