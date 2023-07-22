/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:47:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 05:30:41 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deque_print_all(t_deque *deque)
{
	for(int i = 0; i < deque->sz; i++)
	{
		printf("ele: %lld\n", deque_get_at(deque, i));
	}
}
