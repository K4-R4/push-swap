/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:07:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 01:28:41 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_front(t_deque *deque, int data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->back = 0;
	}
	else if (deque->front == 0)
		deque->front = deque->sz - 1;
	else
		deque->front--;
	deque->buffer[deque->front] = data;
}

void	deque_push_back(t_deque *deque, int data)
{
	if (deque_is_full(deque))
		return ;
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->back = 0;
	}
	else if (deque->back == deque->sz - 1)
		deque->back = 0;
	else
		deque->back++;
	deque->buffer[deque->back] = data;
}

int		*deque_pop_front(t_deque *deque)
{
	int		*data;

	if (deque_is_empty(deque))
		return (NULL);
	data = &deque->buffer[deque->front];
	if (deque->front == deque->back)
	{
		deque->front = -1;
		deque->back = -1;
	}
	else if (deque->front == deque->sz - 1)
		deque->front = 0;
	else
		deque->front++;
	return (data);
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
