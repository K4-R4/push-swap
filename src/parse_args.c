/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:20:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 21:12:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	get_arg_count(char **num_list)
{
	long long	cnt;

	cnt = 0;
	while (*num_list++)
		cnt++;
	return (cnt);
}

static void		compression_helper(t_stacks *stacks, int *buffer)
{
	long long	fixed;
	long long	idx;
	long long	cnt;

	fixed = 0;
	while (fixed < stacks->a.capacity)
	{
		idx = 0;
		cnt = 0;
		while (idx < stacks->a.capacity)
		{
			if (buffer[idx] < buffer[fixed])
				cnt++;
			idx++;
		}
		deque_push_back(&stacks->a, cnt);
		fixed++;
	}
}

static bool		compression(t_stacks *stacks , char **num_list)
{
	int		*buffer;
	size_t	idx;

	buffer = (int *)ft_calloc(stacks->a.capacity, sizeof (int));
	if (!buffer)
		return (false);
	idx = 0;
	while (num_list[idx])
	{
		buffer[idx] = ft_atoi(num_list[idx]);
		idx++;
	}
	compression_helper(stacks, buffer);
	return (true);
}

static bool		init_stacks(t_stacks *stacks, long long capacity)
{
	deque_init(&stacks->a, capacity);
	deque_init(&stacks->b, capacity);
	if (!stacks->a.buffer || !stacks->b.buffer)
		return (false);
	return (true);
}

bool	parse_arg(t_stacks *stacks, char *arg)
{
	char	**num_list;
	long long	capacity;

	num_list = ft_split(arg, ' ');
	if (!num_list)
		return (false);
	capacity = get_arg_count(num_list);
	if (!is_valid_arg(num_list))
		return (false);
	if (!init_stacks(stacks, capacity))
		return (false);
	if (!compression(stacks, num_list))
		return (false);
	return (true);
}
