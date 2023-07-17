/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:49:47 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 09:51:33 by tkuramot         ###   ########.fr       */
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
