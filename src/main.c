/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 23:39:50 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	deque_print_all(t_deque *deque)
{
	long long		*ele;

	while (true)
	{
		ele = deque_pop_front(deque);
		if (!ele)
			return ;
		printf("%lld\n", *ele);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc != 2)
	{
		ft_printf("invalid usage\n");
		return (0);
	}
	if (!parse_arg(&stacks, argv[1]))
	{
		exit(1);
	}
	sort(&stacks);

	printf("===========AFTER\n");
	printf("STACK A\n");
	deque_print_all(&stacks.a);
	printf("STACK B\n");
	deque_print_all(&stacks.b);
	return (0);
}
