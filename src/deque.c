/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:36:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/09 23:02:16 by tkuramot         ###   ########.fr       */
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

void	deque_push_front(t_deque *deque, int data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->front == 0)
		deque->front = deque->sz - 1;
	else
		deque->front--;
	deque->buffer[deque->front] = data;
}

void	deque_push_back(t_deque *deque, int data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->back == deque->sz - 1)
		deque->back = 0;
	else
		deque->back++;
	deque->buffer[deque->back] = data;
}

int		*deque_pop_back(t_deque *deque)
{
	int		*data;

	if (deque_is_empty(deque))
		return (NULL);
	data = &deque->buffer[deque->back];
	if (deque->front == deque->back)
	{
		deque->front = -1;
		deque->back = -1;
	}
	else if (deque->back == 0)
		deque->back = deque->sz - 1;
	else
		deque->back--;
	return (data);
}

void	deque_free_buffer(t_deque *deque)
{
	free(deque->buffer);
}
