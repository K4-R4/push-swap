/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:00:10 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 20:44:06 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	my_abs(long long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

long long	my_min(long long a, long long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static void	free_stacks(t_stacks *stacks)
{
	deque_free_buffer(&stacks->a);
	deque_free_buffer(&stacks->b);
	free(stacks->alpha);
	free(stacks->beta);
	free(stacks->instructions);
}

long long	my_exit(char *message, t_stacks *stacks, int exit_code)
{
	if (message)
		ft_printf("%s", message);
	if (stacks->initialized)
		free_stacks(stacks);
	exit(exit_code);
}
