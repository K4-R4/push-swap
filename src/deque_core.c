/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:07:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 08:48:28 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_front(t_deque *deque, long long data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->back = 0;
	}
	else if (deque->front == 0)
		deque->front = deque->capacity - 1;
	else
		deque->front--;
	deque->buffer[deque->front] = data;
	deque->sz++;
}

void	deque_push_back(t_deque *deque, long long data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->back = 0;
	}
	else if (deque->back == deque->capacity - 1)
		deque->back = 0;
	else
		deque->back++;
	deque->buffer[deque->back] = data;
	deque->sz++;
}

long long		deque_pop_front(t_deque *deque)
{
	long long		data;

	if (deque_is_empty(deque))
		return (-1);
	data = deque->buffer[deque->front];
	if (deque->front == deque->back)
	{
		deque->front = -1;
		deque->back = -1;
	}
	else if (deque->front == deque->capacity - 1)
		deque->front = 0;
	else
		deque->front++;
	deque->sz--;
	return (data);
}

long long		deque_pop_back(t_deque *deque)
{
	long long		data;

	if (deque_is_empty(deque))
		return (-1);
	data = deque->buffer[deque->back];
	if (deque->front == deque->back)
	{
		deque->front = -1;
		deque->back = -1;
	}
	else if (deque->back == 0)
		deque->back = deque->capacity - 1;
	else
		deque->back--;
	deque->sz--;
	return (data);
}

long long	deque_get_at(t_deque *deque, long long idx)
{
	if (deque_is_empty(deque))
		return (-1);
	if (deque->front + idx < deque->capacity)
		return deque->buffer[deque->front + idx];
	else
		return deque->buffer[(deque->front + idx) % deque->capacity];
}
