/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:12:32 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/20 10:27:57 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		execute_op(t_stacks *stacks, char cur_sta, long long op)
{
	// printf("OPS: %c, %lld\n", cur_sta, op);
	if (op > 0)
		while (op--)
			stack_rotate(stacks, cur_sta);
	else
		while (op++)
			stack_rrotate(stacks, cur_sta);
}

static void		compress_ops(t_stacks *stacks, long long idx)
{
	long long	a_ops;
	long long	b_ops;
	long long	common_ops;

	a_ops = stacks->alpha[idx];
	b_ops = stacks->beta[idx];
	if (a_ops * b_ops < 0)
		return ;
	common_ops = my_min(my_abs(a_ops), my_abs(b_ops));
	stacks->alpha[idx] -= common_ops;
	stacks->beta[idx] -= common_ops;
	if (stacks->alpha[idx] > 0)
		while (common_ops--)
			stack_rr(stacks);
	else
		while (common_ops--)
			stack_rrr(stacks);
}

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
			ops = my_abs(stacks->alpha[idx_b]) + my_abs(stacks->beta[idx_b]);
			if (ops < min_ops)
			{
				min_idx_b = idx_b;
				min_ops = ops;
			}
			idx_b++;
		}
		/*
		printf("STACK A =======\n");
		deque_print_all(&stacks->a);
		printf("STACK B =======\n");
		deque_print_all(&stacks->b);
		*/
		compress_ops(stacks, min_idx_b);
		execute_op(stacks, 'a', stacks->alpha[min_idx_b]);
		execute_op(stacks, 'b', stacks->beta[min_idx_b]);
		stack_push(stacks, 'a');
	}
}
