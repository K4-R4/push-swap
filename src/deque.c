/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:36:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 02:03:00 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_init(t_deque *deque, long long capacity)
{
	deque->capacity = capacity;
	deque->sz = 0;
	deque->front = -1;
	deque->back = 0;
	deque->buffer = ft_calloc(capacity, sizeof (int));
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
