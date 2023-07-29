/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 19:19:43 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
*/

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.initialized = false;
	if (argc <= 1)
		my_exit(STDOUT_FILENO, NULL, &stacks, 1);
	if (!parse_arg(&stacks, argc, argv))
		my_exit(STDERR_FILENO, "Error\n", &stacks, 1);
	if (is_sorted(&stacks))
		my_exit(STDOUT_FILENO, NULL, &stacks, 0);
	sort(&stacks);
	ft_printf("%s", stacks.instructions);
	my_exit(STDOUT_FILENO, NULL, &stacks, 0);
}
