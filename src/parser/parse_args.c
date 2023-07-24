/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:20:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/23 17:53:02 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"

static long long	get_arg_count(char **num_list)
{
	long long	cnt;

	cnt = 0;
	while (*num_list++)
		cnt++;
	return (cnt);
}

static void		compression_helper(t_stacks *stacks)
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
			if (stacks->alpha[idx] < stacks->alpha[fixed])
				cnt++;
			idx++;
		}
		deque_push_back(&stacks->a, cnt);
		fixed++;
	}
}

static void		compression(t_stacks *stacks , char **num_list)
{
	size_t	idx;

	idx = 0;
	while (num_list[idx])
	{
		stacks->alpha[idx] = ft_atoi(num_list[idx]);
		idx++;
	}
	compression_helper(stacks);
}

static bool		init_stacks(t_stacks *stacks, long long capacity)
{
	stacks->flag_print = true;
	deque_init(&stacks->a, capacity);
	if (!stacks->a.buffer)
		return (false);
	deque_init(&stacks->b, capacity);
	if (!stacks->b.buffer)
		return (false);
	stacks->alpha = (long long *)ft_calloc(capacity, sizeof (long long));
	if (!stacks->alpha)
		return (false);
	stacks->beta = (long long *)ft_calloc(capacity, sizeof (long long));
	if (!stacks->beta)
		return (false);
	return (true);
}

bool	parse_arg(t_stacks *stacks, int argc, char **argv)
{
	char	**num_list;
	long long	capacity;

	if (argc == 2)
	{
		num_list = ft_split(argv[1], ' ');
		if (!num_list)
			return (false);
	}
	else
	{
		num_list = (char **)ft_calloc(argc, sizeof (char *));
		if (!num_list)
			return false;
		ft_memcpy(num_list, &argv[1], sizeof (char *) * (argc - 1));
	}
	capacity = get_arg_count(num_list);
	if (!is_valid_arg(num_list))
		return (false);
	if (!init_stacks(stacks, capacity))
		return (false);
	compression(stacks, num_list);
	return (true);
}
