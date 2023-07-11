/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:31:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 22:56:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

long long	*deque_get_front(t_deque *deque)
{
	if (deque_is_empty(deque))
		return (NULL);
	return (&deque->buffer[deque->front]);
}

long long	*deque_get_back(t_deque *deque)
{
	if (deque_is_empty(deque))
		return (NULL);
	return (&deque->buffer[deque->back]);
}
