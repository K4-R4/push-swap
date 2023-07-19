/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:12:32 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/19 11:18:31 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#include "push_swap.h"
void		push_a_back(t_stacks *stacks)
{
	long long	cnt;
	long long	b_front;
	long long	a_front;
	long long	a_back;

	while (stacks->b.sz)
	{
		cnt = 0;
		b_front = stack_get_at(stacks, 'b', 0);
		a_front = stack_get_at(stacks, 'a', 0);
		a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);

		/*
		ft_printf("PASSED\n");
		ft_printf("%d\n", b_front);
		ft_printf("%d\n", a_front);
		printf("===========BEFORE\n");
		printf("STACK A\n");
		deque_print_all(&stacks->a);
		printf("STACK B\n");
		deque_print_all(&stacks->b);
		*/

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
		else if (b_front >= a_back)
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
}
