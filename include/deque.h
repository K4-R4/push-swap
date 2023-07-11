/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:12:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 14:14:42 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
#define DEQUE_H

#include "libft.h"

typedef struct s_deque
{
    long long   capacity;
    long long   sz;
	long long	front;
	long long	back;
	long long	*buffer;
}				t_deque;

void	deque_init(t_deque *deque, long long sz);
bool	deque_is_full(t_deque *deque);
bool	deque_is_empty(t_deque *deque);
void	deque_free_buffer(t_deque *deque);
void	deque_push_front(t_deque *deque, int data);
void	deque_push_back(t_deque *deque, int data);
long long		*deque_pop_front(t_deque *deque);
long long		*deque_pop_back(t_deque *deque);

#endif
