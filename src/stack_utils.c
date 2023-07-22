/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:49:47 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 16:23:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_save_instruction(t_stacks *stacks, char *instruction)
{
	char	*instruction_dup;
	char	*new_instructions;

	instruction_dup = ft_strdup(instruction);
	if (!instruction_dup)
		my_exit(NULL, 1);
	new_instructions = ft_strjoin(stacks->instructions, instruction_dup);
	if (!new_instructions)
		my_exit(NULL, 1);
}

long long	stack_get_at(t_stacks *stacks, char sta, long long idx)
{
	if (sta == 'a')
		return deque_get_at(&stacks->a, idx);
	else
		return deque_get_at(&stacks->b, idx);
}

long long	stack_get_min_value(t_stacks *stacks, char cur_sta, long long n)
{
	long long	idx;
	long long	min_sta;
	long long	ele;

	idx = 0;
	min_sta = LLONG_MAX;
	while (idx < n)
	{
		ele = stack_get_at(stacks, cur_sta, idx);
		if (ele < min_sta)
			min_sta = ele;
		idx++;
	}
	return (min_sta);
}

long long	stack_get_min_idx(t_stacks *stacks, char cur_sta, long long n)
{
	long long	idx;
	long long	min_idx;
	long long	min_sta;
	long long	ele;

	idx = 0;
	min_sta = LLONG_MAX;
	while (idx < n)
	{
		ele = stack_get_at(stacks, cur_sta, idx);
		if (ele < min_sta)
		{
			min_idx = idx;
			min_sta = ele;
		}
		idx++;
	}
	return (min_idx);
}
