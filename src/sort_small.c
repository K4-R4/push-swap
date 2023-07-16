/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:06:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/16 19:00:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"

static void	sort_small_3_helper(t_stacks *stacks, char cur_sta, long long *sta[])
{
	if (*sta[0] < *sta[1] && *sta[1] < *sta[2])
		return ;
	else if (*sta[0] < *sta[1] && *sta[1] > *sta[2])
	{
		stack_rrotate(stacks, cur_sta);
		stack_swap(stacks, cur_sta);
	}
}

void	sort_small_3(t_stacks *stacks, char cur_sta)
{
	long long	*sta[3];
	long long	idx;

	idx = 0;
	while (idx < 3)
	{
		if (cur_sta == 'a')
		{
			sta[idx] = deque_pop_front(&stacks->a);
			deque_push_back(&stacks->a, *sta[idx]);
		}
		else
		{
			sta[idx] = deque_pop_front(&stacks->b);
			deque_push_back(&stacks->b, *sta[idx]);
		}
	}
}

void	sort_small_2(t_stacks *stacks, char cur_sta)
{
	long long	*sta[2];

	if (cur_sta == 'a')
	{
		sta[0] = deque_get_front(&stacks->a);
		sta[1] = deque_get_front(&stacks->a);
	}
	else
	{
		sta[0] = deque_get_front(&stacks->b);
		sta[1] = deque_get_front(&stacks->b);
	}
	if (*sta[0] < *sta[1])
		stack_swap(stacks, cur_sta);
}