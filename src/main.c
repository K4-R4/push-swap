/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 21:18:28 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	deque_print_all(t_deque *deque)
{
	long long		*ele;

	printf("========================\n");
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
	long long	*lis;
	long long	length;

	if (argc != 2)
	{
		ft_printf("invalid usage\n");
		return (0);
	}
	if (!parse_arg(&stacks, argv[1]))
	{
		exit(1);
	}
	lis = get_lis(&stacks, &length);
	printf("LIS %lld\n", length);
	while (length)
	{
		printf("===%lld\n", *lis);
		lis++;
		length--;
	}
	deque_print_all(&stacks.a);
	return (0);
}
