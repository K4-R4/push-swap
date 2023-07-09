/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:36:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/09 23:08:00 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deque_init(t_deque *deque, long long sz)
{
	deque->front = -1;
	deque->back = 0;
	deque->buffer = ft_calloc(sz, sizeof (int));
}

bool	deque_is_full(t_deque *deque)
{
	return ((deque->front == 0 && deque->back == deque->sz - 1)
		|| deque->front == deque->back + 1);
}

bool	deque_is_empty(t_deque *deque)
{
	return (deque->front == -1);
}


void	deque_free_buffer(t_deque *deque)
{
	free(deque->buffer);
}
