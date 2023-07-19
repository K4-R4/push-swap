/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/19 16:18:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// Push (e - s) elements in the closed section from stack A to stack B
static void		push_b_range(t_stacks *stacks, long long pivot_small, long long pivot_large)
{
	long long	n_to_push;
	long long	sta_first;

	n_to_push = pivot_large;
	while (n_to_push)
	{
		sta_first = stack_get_at(stacks, 'a', 0);
		if (0 <= sta_first && sta_first <= pivot_large - 1)
		{
			if (0 <= sta_first && sta_first <= pivot_small - 1)
			{
				stack_push(stacks, 'b');
				stack_rotate(stacks, 'b');
			}
			else
				stack_push(stacks, 'b');
			n_to_push--;
		}
		else
			stack_rotate(stacks, 'a');
	}
}

// Push elements in stack A until its size reaches less than 5,
// and then sort stack A
static void	prepare_sort(t_stacks *stacks)
{
	long long	pivot_small;
	long long	pivot_large;
	long long	ele;

	pivot_small = stacks->a.capacity / 3;
	pivot_large = stacks->a.capacity - pivot_small;
	push_b_range(stacks, pivot_small, pivot_large);
	while (stacks->a.sz > 5)
	{
		ele = stack_get_at(stacks, 'a', 0);
		if (ele < stacks->a.capacity - 5)
			stack_push(stacks, 'b');
		else
			stack_rotate(stacks, 'a');
	}
	sort(stacks);
}

void	sort_many(t_stacks *stacks)
{
	prepare_sort(stacks);
	execute_ops(stacks);
}
