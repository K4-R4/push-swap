/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:27:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 23:00:03 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_deque();
void	test_stack();

int		main(void)
{
	test_deque();
	test_stack();
	return (0);
}

void	deque_print_all(t_deque *deque)
{
	int		*ele;

	printf("========================\n");
	while (true)
	{
		ele = deque_pop_front(deque);
		if (!ele)
			return ;
		printf("%d\n", *ele);
	}
}

void	test_stack()
{
	t_stacks stacks;

	printf("TEST STACK\n");
	deque_init(&stacks.a, 10);
	deque_init(&stacks.b, 10);
	for(int i = 0; i < 10; i++)
		deque_push_back(&stacks.a, i);
	for(int i = 0; i < 10; i++)
		stack_pb(&stacks);
	for(int i = 0; i < 5; i++)
		stack_rr(&stacks);
	for(int i = 0; i < 5; i++)
		stack_pb(&stacks);
	for(int i = 0; i < 5; i++)
		stack_pa(&stacks);
	printf("STACK A\n");
	deque_print_all(&stacks.a);
	printf("STACK B\n");
	deque_print_all(&stacks.b);
}

void	test_deque()
{
	t_deque dq;

	printf("TEST DEQUE\n");
	deque_init(&dq, 10);
	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	deque_print_all(&dq);

	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	deque_print_all(&dq);

	deque_push_back(&dq, 10);
	deque_push_back(&dq, 11);
	deque_push_back(&dq, 12);
	deque_push_front(&dq, 111);
	deque_push_front(&dq, 111);
	deque_push_front(&dq, 111);
	deque_print_all(&dq);
}
