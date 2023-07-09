/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:27:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 01:41:02 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

int		main(void)
{
	t_deque dq;

	deque_init(&dq, 10);
	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%p\n", deque_pop_front(&dq));
	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	printf("%d\n", *deque_pop_back(&dq));
	printf("%d\n", *deque_pop_back(&dq));
	printf("%d\n", *deque_pop_back(&dq));
	printf("%p\n", deque_pop_back(&dq));
	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	deque_push_front(&dq, 111);
	deque_push_front(&dq, 111);
	deque_push_front(&dq, 111);
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%d\n", *deque_pop_front(&dq));
	printf("%p\n", deque_pop_front(&dq));
	return (0);
}
