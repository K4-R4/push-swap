/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:47:04 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 20:47:19 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	deque_get_min_value(t_deque *deq)
{
	long long	idx;
	long long	min_sta;
	long long	ele;

	idx = 0;
	min_sta = LLONG_MAX;
	while (idx < deq->sz)
	{
		ele = deque_get_at(deq, idx);
		if (ele < min_sta)
			min_sta = ele;
		idx++;
	}
	return (min_sta);
}

long long	deque_get_min_idx(t_deque *deq)
{
	long long	idx;
	long long	min_idx;
	long long	min_sta;
	long long	ele;

	idx = 0;
	min_sta = LLONG_MAX;
	while (idx < deq->sz)
	{
		ele = deque_get_at(deq, idx);
		if (ele < min_sta)
		{
			min_idx = idx;
			min_sta = ele;
		}
		idx++;
	}
	return (min_idx);
}
