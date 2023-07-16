/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:31:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 00:40:10 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

long long	deque_get_at(t_deque *deque, long long idx)
{
	if (deque_is_empty(deque))
		return (-1);
	if (deque->front + idx < deque->capacity)
		return deque->buffer[deque->front + idx];
	else
		return deque->buffer[(deque->front + idx) % deque->capacity];
}
