/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:12:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/09 23:15:02 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
#define DEQUE_H

#include "libft.h"

typedef struct s_deque
{
    long long  sz;
	long long	front;
	long long	back;
	int	*buffer;
}				t_deque;

void	deque_init(t_deque *deque, long long sz);
bool	deque_is_full(t_deque *deque);

#endif
