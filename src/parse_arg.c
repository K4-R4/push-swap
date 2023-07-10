/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:20:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 23:33:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"

static size_t	get_arg_count(char *arg)
{
	return (0);
}

static bool		init_stacks(t_stacks *stacks, char *arg)
{
	size_t	sz;

	sz = get_arg_count(arg);
	deque_init(&stacks->a, sz);
	deque_init(&stacks->b, sz);
	if (!stacks->a.buffer || !stacks->b.buffer)
		return (false);
	return (true);
}

bool	parse_arg(t_stacks *stacks, char *arg)
{
	if (!is_valid_arg(arg) || !init_stacks(stacks, arg))
		return (false);
	return (true);
}
