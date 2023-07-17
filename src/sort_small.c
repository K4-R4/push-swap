/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:04:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 10:15:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

// Push the smallest two elements to the other stacks and
// sort the elements in the stacks respectively
void	sort_small_4(t_stacks *stacks, char cur_sta)
{
	long long	pivot;
	long long	tmp;
	long long	idx;

	pivot = get_stack_min(stacks, cur_sta, 4) + 1;
	idx = 0;
	while (idx < 4)
	{
		tmp = stack_get_at(stacks, cur_sta, idx);
		if (tmp > pivot)
			stack_rotate(stacks, 'a' + (cur_sta == 'a'));
		else
			stack_push(stacks, 'a' + (cur_sta == 'a'));
	}
	sort_small_2(stacks, 'a');
	sort_small_2(stacks, 'b');
}

