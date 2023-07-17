/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:06:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 09:56:45 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_small_3(t_stacks *stacks, char cur_sta)
{
	long long	sta[3];
	long long	idx;

	idx = 0;
	while (idx < 3)
	{
		sta[idx] = stack_get_at(stacks, cur_sta, idx);
		idx++;
	}
	if (sta[0] < sta[1] && sta[1] > sta[2])
	{
		stack_rrotate(stacks, cur_sta);
		stack_swap(stacks, cur_sta);
	}
	else if (sta[0] > sta[1] && sta[1] < sta[2])
		stack_swap(stacks, cur_sta);
	else if (sta[0] < sta[1] && sta[1] > sta[2])
		stack_rrotate(stacks, cur_sta);
	else if (sta[0] > sta[1] && sta[1] < sta[2])
		stack_rotate(stacks, cur_sta);
	else if (sta[0] > sta[1] && sta[1] > sta[2])
	{
		stack_rotate(stacks, cur_sta);
		stack_swap(stacks, cur_sta);
	}
}

void	sort_small_2(t_stacks *stacks, char cur_sta)
{
	long long	sta[2];

	if (cur_sta == 'a')
	{
		sta[0] = deque_get_at(&stacks->a, 0);
		sta[1] = deque_get_at(&stacks->a, 1);
	}
	else
	{
		sta[0] = deque_get_at(&stacks->b, 0);
		sta[1] = deque_get_at(&stacks->b, 1);
	}
	if (sta[0] < sta[1])
		stack_swap(stacks, cur_sta);
}
