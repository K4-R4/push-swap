/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 21:10:38 by tkuramot         ###   ########.fr       */
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
		my_exit(NULL, &stacks, 1);
	if (!parse_arg(&stacks, argc, argv))
		my_exit("Error\n", &stacks, 1);
	sort(&stacks);
	ft_printf("%s", stacks.instructions);
	my_exit(NULL, &stacks, 0);
}
