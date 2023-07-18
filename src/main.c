/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/18 23:09:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
	{
		ft_printf("invalid usage\n");
		return (0);
	}
	if (!parse_arg(&stacks, argc, argv))
	{
		exit(1);
	}
	/*
	printf("===========BEFORE\n");
	printf("STACK A\n");
	deque_print_all(&stacks.a);
	printf("STACK B\n");
	deque_print_all(&stacks.b);
	*/

	sort(&stacks);

	/*
	printf("===========AFTER\n");
	printf("STACK A\n");
	deque_print_all(&stacks.a);
	printf("STACK B\n");
	deque_print_all(&stacks.b);
	*/
	return (0);
}
