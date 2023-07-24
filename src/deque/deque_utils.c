/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:36:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 20:26:28 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_init(t_deque *deque, long long capacity)
{
	deque->capacity = capacity;
	deque->sz = 0;
	deque->front = -1;
	deque->back = 0;
	deque->buffer = (long long *)ft_calloc(capacity, sizeof (long long));
}

bool	deque_is_full(t_deque *deque)
{
	return (deque->sz == deque->capacity);
}

bool	deque_is_empty(t_deque *deque)
{
	return (deque->sz == 0);
}

void	deque_free_buffer(t_deque *deque)
{
	free(deque->buffer);
}

long long	deque_get_at(t_deque *deque, long long idx)
{
	if (deque_is_empty(deque))
		return (-1);
	if (deque->front + idx < deque->capacity)
		return (deque->buffer[deque->front + idx]);
	else
		return (deque->buffer[(deque->front + idx) % deque->capacity]);
}
