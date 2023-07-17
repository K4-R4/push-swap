/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:30:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 10:00:06 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// Get the min value of the stack from top n elements
long long	get_stack_min(t_stacks *stacks, char cur_sta, long long n)
{
	long long	idx;
	long long	tmp;
	long long	sta_min;

	idx = 0;
	sta_min = LLONG_MAX;
	while (idx < n)
	{
		tmp = stack_get_at(stacks, cur_sta, idx);
		if (tmp < sta_min)
			sta_min = tmp;
	}
	return (sta_min);
}
