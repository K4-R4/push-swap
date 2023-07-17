/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:49:47 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 11:23:06 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

long long	stack_get_at(t_stacks *stacks, char sta, long long idx)
{
	if (sta == 'a')
		return deque_get_at(&stacks->a, idx);
	else
		return deque_get_at(&stacks->b, idx);
}

long long	stack_get_min(t_stacks *stacks, char cur_sta, long long n)
{
	long long	idx;
	long long	ele;
	long long	sta_min;

	idx = 0;
	sta_min = LLONG_MIN;
	while (idx < n)
	{
		ele = stack_get_at(stacks, cur_sta, idx);
		if (ele < sta_min)
			sta_min = ele;
		idx++;
	}
	return (sta_min);
}
