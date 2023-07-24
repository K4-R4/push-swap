/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 20:28:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
*/

void	free_stacks(t_stacks *stacks)
{
	deque_free_buffer(&stacks->a);
	deque_free_buffer(&stacks->b);
	free(stacks->alpha);
	free(stacks->beta);
	free(stacks->instructions);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
		my_exit(NULL, 1);
	if (!parse_arg(&stacks, argc, argv))
		my_exit("Error\n", 1);
	sort(&stacks);
	ft_printf("%s", stacks.instructions);
	free_stacks(&stacks);
	return (0);
}
