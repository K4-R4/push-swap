/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:06:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 12:06:23 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_small_5(t_stacks *stacks, char cur_sta)
{
	char		another_sta;
	long long	pivot;
	long long	idx;

	another_sta = 'a' + (cur_sta == 'a');
	pivot = stack_get_min(stacks, cur_sta, 5) + 1;
	idx = 0;
	while (idx < 5)
	{
		if (stack_get_at(stacks, cur_sta, 0) > pivot)
			stack_rotate(stacks, cur_sta);
		else
			stack_push(stacks, another_sta);
		idx++;
	}
	sort_small_2(stacks, cur_sta);
	sort_small_3(stacks, another_sta);
	idx = 0;
	while (idx < 3)
	{
		stack_rrotate(stacks, another_sta);
		stack_push(stacks, cur_sta);
		idx++;
	}
}

#include "push_swap.h"
void	sort_small_4(t_stacks *stacks, char cur_sta)
{
	char		another_sta;
	long long	pivot;
	long long	idx;

	another_sta = 'a' + (cur_sta == 'a');
	pivot = stack_get_min(stacks, cur_sta, 4) + 1;
	idx = 0;
	while (idx < 4)
	{
		long long tmp = stack_get_at(stacks, cur_sta, 0);
		ft_printf("tmp = %d, pivot = %d, tmp > pivot = %d\n", tmp, pivot, tmp > pivot);
		if (tmp > pivot)
			stack_rotate(stacks, cur_sta);
		else
			stack_push(stacks, another_sta);
		idx++;
	}
	/*
	ft_printf("|||||||||||||||||||||||||||||||||||\n");
	ft_printf("stacks after split\n");
	deque_print_all(&stacks->a);
	deque_print_all(&stacks->b);
	ft_printf("|||||||||||||||||||||||||||||||||||\n");
	*/
	sort_small_2(stacks, cur_sta);
	sort_small_2(stacks, another_sta);
	idx = 0;
	while (idx < 2)
	{
		stack_rrotate(stacks, another_sta);
		stack_push(stacks, cur_sta);
		idx++;
	}
}

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

	sta[0] = stack_get_at(stacks, cur_sta, 0);
	sta[1] = stack_get_at(stacks, cur_sta, 1);
	if (sta[0] < sta[1])
		stack_swap(stacks, cur_sta);
}
