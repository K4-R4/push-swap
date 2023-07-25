/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:00:10 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/25 20:42:52 by tkuramot         ###   ########.fr       */
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

long long	my_exit(int fd, char *message, t_stacks *stacks, int exit_code)
{
	if (message)
		ft_putstr_fd(message, fd);
	if (stacks->initialized)
		free_stacks(stacks);
	exit(exit_code);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((const unsigned char)*s1 - (const unsigned char)*s2);
}
